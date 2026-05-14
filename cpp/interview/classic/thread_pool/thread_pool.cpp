// 简易线程池：mutex + condition_variable + queue<function<void()>>
#include <bits/stdc++.h>
#include <cassert>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

class ThreadPool {
public:
    explicit ThreadPool(size_t n) : stop_(false), joined_(false) {
        for (size_t i = 0; i < n; ++i) {
            workers_.emplace_back([this] { loop(); });
        }
    }

    ~ThreadPool() { shutdown(); }

    void enqueue(function<void()> fn) {
        {
            lock_guard<mutex> lk(mtx_);
            if (stop_) throw runtime_error("pool stopped");
            tasks_.push(move(fn));
        }
        cv_.notify_one();
    }

    void wait_idle() {
        unique_lock<mutex> lk(mtx_);
        idle_cv_.wait(lk, [&] { return pending_ == 0 && tasks_.empty(); });
    }

    void shutdown() {
        unique_lock<mutex> guard(join_mtx_);
        if (joined_) return;
        {
            unique_lock<mutex> lk(mtx_);
            idle_cv_.wait(lk, [&] { return pending_ == 0 && tasks_.empty(); });
            stop_ = true;
        }
        cv_.notify_all();
        for (auto& t : workers_) {
            if (t.joinable()) t.join();
        }
        joined_ = true;
    }

private:
    vector<thread> workers_;
    queue<function<void()>> tasks_;
    mutex mtx_;
    mutex join_mtx_;
    condition_variable cv_;
    condition_variable idle_cv_;
    int pending_ = 0;
    bool stop_;
    bool joined_;

    void loop() {
        while (true) {
            function<void()> task;
            {
                unique_lock<mutex> lk(mtx_);
                cv_.wait(lk, [&] { return stop_ || !tasks_.empty(); });
                if (stop_ && tasks_.empty()) return;
                task = move(tasks_.front());
                tasks_.pop();
                ++pending_;
            }
            task();
            {
                lock_guard<mutex> lk(mtx_);
                --pending_;
                if (pending_ == 0 && tasks_.empty()) idle_cv_.notify_all();
            }
        }
    }
};

int main() {
    mutex m;
    vector<int> acc;
    {
        ThreadPool pool(4);
        for (int i = 0; i < 40; ++i) {
            pool.enqueue([i, &m, &acc] {
                lock_guard<mutex> lk(m);
                acc.push_back(i);
            });
        }
        pool.wait_idle();
    }
    assert((int)acc.size() == 40);
    sort(acc.begin(), acc.end());
    for (int i = 0; i < 40; ++i) assert(acc[i] == i);
    cout << "thread_pool OK" << endl;
    return 0;
}
