// 读写锁（读者优先）：与 Python 版同构（C++17）
#include <bits/stdc++.h>
#include <cassert>
#include <chrono>
#include <mutex>
#include <thread>
using namespace std;

class RWLock {
public:
    void read_lock() {
        lock_guard<mutex> lk(guard_);
        if (++readers_ == 1) write_.lock();
    }

    void read_unlock() {
        lock_guard<mutex> lk(guard_);
        if (--readers_ == 0) write_.unlock();
    }

    void write_lock() { write_.lock(); }

    void write_unlock() { write_.unlock(); }

private:
    mutex guard_;
    mutex write_;
    int readers_ = 0;
};

int main() {
    RWLock rw;
    atomic<int> x{0};
    atomic<bool> go{false};

    auto reader = [&] {
        while (!go.load()) this_thread::yield();
        for (int i = 0; i < 20; ++i) {
            rw.read_lock();
            int v = x.load();
            (void)v;
            rw.read_unlock();
            this_thread::sleep_for(chrono::microseconds(10));
        }
    };

    auto writer = [&] {
        while (!go.load()) this_thread::yield();
        for (int i = 0; i < 50; ++i) {
            rw.write_lock();
            x.fetch_add(1);
            rw.write_unlock();
            this_thread::sleep_for(chrono::microseconds(5));
        }
    };

    vector<thread> ts;
    for (int i = 0; i < 4; ++i) ts.emplace_back(reader);
    ts.emplace_back(writer);
    go = true;
    for (auto& t : ts) t.join();
    assert(x.load() == 50);
    cout << "rwlock OK" << endl;
    return 0;
}
