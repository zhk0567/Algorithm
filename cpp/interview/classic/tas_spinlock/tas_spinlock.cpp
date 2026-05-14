// 纯 TAS 自旋锁：std::atomic_flag::test_and_set / clear（C++11）
#include <atomic>
#include <cassert>
#include <iostream>
#include <thread>
#include <vector>

class TASSpinLock {
public:
    void lock() {
        while (flag_.test_and_set(std::memory_order_acquire)) std::this_thread::yield();
    }

    void unlock() { flag_.clear(std::memory_order_release); }

private:
    std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
};

int main() {
    TASSpinLock lk;
    std::atomic<int> cnt{0};

    auto worker = [&] {
        for (int i = 0; i < 100; ++i) {
            lk.lock();
            cnt.fetch_add(1, std::memory_order_relaxed);
            lk.unlock();
        }
    };

    std::vector<std::thread> ts;
    for (int i = 0; i < 10; ++i) ts.emplace_back(worker);
    for (auto& t : ts) t.join();
    assert(cnt.load() == 1000);
    std::cout << "tas_spinlock OK" << std::endl;
    return 0;
}
