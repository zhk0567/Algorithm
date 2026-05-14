// 手写计数信号量：mutex + condition_variable（C++17）
#include <bits/stdc++.h>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;

class Semaphore {
public:
    explicit Semaphore(int value) : count_(value) {
        if (value < 0) throw invalid_argument("value>=0");
    }

    void acquire() {
        unique_lock<mutex> lk(mtx_);
        cv_.wait(lk, [&] { return count_ > 0; });
        --count_;
    }

    bool try_acquire() {
        lock_guard<mutex> lk(mtx_);
        if (count_ == 0) return false;
        --count_;
        return true;
    }

    void release(int n = 1) {
        if (n < 1) throw invalid_argument("n>=1");
        lock_guard<mutex> lk(mtx_);
        count_ += n;
        for (int i = 0; i < n; ++i) cv_.notify_one();
    }

private:
    mutex mtx_;
    condition_variable cv_;
    int count_;
};

int main() {
    Semaphore sem(2);
    mutex pk;
    atomic<int> cur{0};
    int peak = 0;

    auto worker = [&] {
        sem.acquire();
        int c = ++cur;
        {
            lock_guard<mutex> lk(pk);
            peak = max(peak, c);
        }
        this_thread::sleep_for(chrono::milliseconds(5));
        --cur;
        sem.release();
    };

    vector<thread> ts;
    for (int i = 0; i < 3; ++i) ts.emplace_back(worker);
    for (auto& t : ts) t.join();
    assert(peak <= 2);

    Semaphore z(0);
    assert(!z.try_acquire());
    z.release();
    assert(z.try_acquire());
    cout << "semaphore OK" << endl;
    return 0;
}
