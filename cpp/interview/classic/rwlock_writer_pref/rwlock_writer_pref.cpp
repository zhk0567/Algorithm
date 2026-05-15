// 读写锁（写者优先）：与 Python 版同构（C++17）
#include <alg_std.hpp>
#include <cassert>
#include <chrono>
#include <mutex>
#include <thread>
using namespace std;

class WriterPreferRWLock {
public:
    void read_lock() {
        read_gate_.lock();
        {
            lock_guard<mutex> lk(guard_);
            if (++readers_ == 1) resource_.lock();
        }
        read_gate_.unlock();
    }

    void read_unlock() {
        lock_guard<mutex> lk(guard_);
        if (--readers_ == 0) resource_.unlock();
    }

    void write_lock() {
        read_gate_.lock();
        resource_.lock();
    }

    void write_unlock() {
        resource_.unlock();
        read_gate_.unlock();
    }

private:
    mutex read_gate_;
    mutex guard_;
    mutex resource_;
    int readers_ = 0;
};

int main() {
    WriterPreferRWLock rw;
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
    cout << "rwlock_writer_pref OK" << endl;
    return 0;
}
