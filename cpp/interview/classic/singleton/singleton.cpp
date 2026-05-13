// 单例模式：Meyers / call_once / 双检锁
#include <bits/stdc++.h>
#include <cassert>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

// 1) Meyers 单例（C++11 起线程安全）
class Meyers {
public:
    static Meyers& instance() {
        static Meyers inst;
        return inst;
    }
    int value() const { return value_; }
    void set(int v) { value_ = v; }

    Meyers(const Meyers&) = delete;
    Meyers& operator=(const Meyers&) = delete;

private:
    Meyers() = default;
    int value_ = 42;
};

// 2) call_once
class OnceSingleton {
public:
    static OnceSingleton& instance() {
        call_once(flag_, [] { inst_.reset(new OnceSingleton()); });
        return *inst_;
    }
    int id() const { return 7; }

private:
    OnceSingleton() = default;
    static once_flag flag_;
    static unique_ptr<OnceSingleton> inst_;
};

once_flag OnceSingleton::flag_;
unique_ptr<OnceSingleton> OnceSingleton::inst_;

// 3) 双检锁（仅供对比，注意 atomic 保序）
class DCLP {
public:
    static DCLP* instance() {
        DCLP* p = inst_.load(memory_order_acquire);
        if (!p) {
            lock_guard<mutex> lk(mtx_);
            p = inst_.load(memory_order_relaxed);
            if (!p) {
                p = new DCLP();
                inst_.store(p, memory_order_release);
            }
        }
        return p;
    }
    int tag() const { return 99; }

private:
    DCLP() = default;
    static atomic<DCLP*> inst_;
    static mutex mtx_;
};

atomic<DCLP*> DCLP::inst_{nullptr};
mutex DCLP::mtx_;

int main() {
    auto& a = Meyers::instance();
    auto& b = Meyers::instance();
    assert(&a == &b);
    a.set(100);
    assert(b.value() == 100);

    assert(&OnceSingleton::instance() == &OnceSingleton::instance());
    assert(OnceSingleton::instance().id() == 7);

    assert(DCLP::instance() == DCLP::instance());
    assert(DCLP::instance()->tag() == 99);

    // 并发取实例 -> 全部相同
    vector<thread> ts;
    array<Meyers*, 32> ptrs{};
    for (int i = 0; i < 32; ++i) {
        ts.emplace_back([i, &ptrs] { ptrs[i] = &Meyers::instance(); });
    }
    for (auto& t : ts) t.join();
    for (auto* p : ptrs) assert(p == ptrs[0]);

    cout << "singleton OK" << endl;
    return 0;
}
