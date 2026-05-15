// Ticket Lock（公平）：atomic 取号 + 自旋等待叫号（教学用，高竞争请加退避）
#include <alg_std.hpp>
#include <cassert>
#include <atomic>
#include <thread>
using namespace std;

class TicketSpinLock {
public:
    void lock() {
        const uint64_t my = next_.fetch_add(1, memory_order_relaxed);
        while (now_.load(memory_order_acquire) != my) this_thread::yield();
    }

    void unlock() { now_.fetch_add(1, memory_order_release); }

private:
    atomic<uint64_t> next_{0};
    atomic<uint64_t> now_{0};
};

int main() {
    TicketSpinLock lk;
    atomic<int> cnt{0};

    auto worker = [&] {
        for (int i = 0; i < 100; ++i) {
            lk.lock();
            cnt.fetch_add(1, memory_order_relaxed);
            lk.unlock();
        }
    };

    vector<thread> ts;
    for (int i = 0; i < 10; ++i) ts.emplace_back(worker);
    for (auto& t : ts) t.join();
    assert(cnt.load() == 1000);
    cout << "ticket_lock OK" << endl;
    return 0;
}
