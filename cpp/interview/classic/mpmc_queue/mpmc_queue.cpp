// 有界 MPMC 无锁队列（int）：序列槽 + turn 位，思路来自 Erik Rigtorp / MPMCQueue（MIT）
#include <atomic>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

struct alignas(64) Cell {
    std::atomic<std::size_t> turn{0};
    int val{0};
};

class IntMpmcQueue {
public:
    explicit IntMpmcQueue(std::size_t capacity) : cap_(capacity), slots_(new Cell[capacity]) {
        assert(capacity >= 1);
        for (std::size_t i = 0; i < cap_; ++i) slots_[i].turn.store(0, std::memory_order_relaxed);
    }

    IntMpmcQueue(const IntMpmcQueue&) = delete;
    IntMpmcQueue& operator=(const IntMpmcQueue&) = delete;

    void push(int v) {
        const std::size_t h = head_.fetch_add(1, std::memory_order_relaxed);
        Cell& s = slots_[idx(h)];
        while (turn_of(h) * 2 != s.turn.load(std::memory_order_acquire)) std::this_thread::yield();
        s.val = v;
        s.turn.store(turn_of(h) * 2 + 1, std::memory_order_release);
    }

    int pop() {
        const std::size_t t = tail_.fetch_add(1, std::memory_order_relaxed);
        Cell& s = slots_[idx(t)];
        while (turn_of(t) * 2 + 1 != s.turn.load(std::memory_order_acquire)) std::this_thread::yield();
        const int out = s.val;
        s.turn.store(turn_of(t) * 2 + 2, std::memory_order_release);
        return out;
    }

private:
    std::size_t idx(std::size_t i) const noexcept { return i % cap_; }
    std::size_t turn_of(std::size_t i) const noexcept { return i / cap_; }

    const std::size_t cap_;
    std::unique_ptr<Cell[]> slots_;
    alignas(64) std::atomic<std::size_t> head_{0};
    alignas(64) std::atomic<std::size_t> tail_{0};
};

int main() {
    constexpr std::size_t kCap = 1024;
    constexpr int kEach = 500;
    IntMpmcQueue q(kCap);
    std::atomic<std::int64_t> sum{0};
    std::atomic<bool> go{false};

    auto producer = [&] {
        while (!go.load(std::memory_order_acquire)) std::this_thread::yield();
        for (int i = 0; i < kEach; ++i) q.push(1);
    };

    auto consumer = [&] {
        while (!go.load(std::memory_order_acquire)) std::this_thread::yield();
        for (int i = 0; i < kEach; ++i) sum.fetch_add(q.pop(), std::memory_order_relaxed);
    };

    std::vector<std::thread> ts;
    for (int i = 0; i < 8; ++i) ts.emplace_back(producer);
    for (int i = 0; i < 8; ++i) ts.emplace_back(consumer);
    go.store(true, std::memory_order_release);
    for (auto& t : ts) t.join();

    assert(sum.load() == static_cast<std::int64_t>(8 * kEach));
    std::cout << "mpmc_queue OK" << std::endl;
    return 0;
}
