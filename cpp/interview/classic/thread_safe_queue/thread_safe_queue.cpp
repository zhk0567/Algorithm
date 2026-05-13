// 线程安全有界阻塞队列：mutex + 两个 condition_variable
#include <bits/stdc++.h>
#include <cassert>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
using namespace std;

template <class T>
class BlockingQueue {
public:
    explicit BlockingQueue(size_t cap) : cap_(cap) {
        if (cap == 0) throw invalid_argument("cap must be positive");
    }

    void push(T item) {
        unique_lock<mutex> lk(mtx_);
        not_full_.wait(lk, [&] { return closed_ || buf_.size() < cap_; });
        if (closed_) throw runtime_error("queue closed");
        buf_.push_back(std::move(item));
        not_empty_.notify_one();
    }

    T pop() {
        unique_lock<mutex> lk(mtx_);
        not_empty_.wait(lk, [&] { return closed_ || !buf_.empty(); });
        if (buf_.empty()) throw runtime_error("queue closed");
        T v = std::move(buf_.front());
        buf_.pop_front();
        not_full_.notify_one();
        return v;
    }

    bool tryPop(T& out, chrono::milliseconds timeout) {
        unique_lock<mutex> lk(mtx_);
        if (!not_empty_.wait_for(lk, timeout, [&] { return closed_ || !buf_.empty(); })) {
            return false;
        }
        if (buf_.empty()) return false;
        out = std::move(buf_.front());
        buf_.pop_front();
        not_full_.notify_one();
        return true;
    }

    void close() {
        {
            lock_guard<mutex> lk(mtx_);
            closed_ = true;
        }
        not_full_.notify_all();
        not_empty_.notify_all();
    }

    size_t size() const {
        lock_guard<mutex> lk(mtx_);
        return buf_.size();
    }

private:
    size_t cap_;
    deque<T> buf_;
    mutable mutex mtx_;
    condition_variable not_full_;
    condition_variable not_empty_;
    bool closed_ = false;
};

int main() {
    BlockingQueue<int> q(8);
    const int nProducer = 4;
    const int per = 1000;
    const int total = nProducer * per;

    vector<thread> producers;
    for (int i = 0; i < nProducer; ++i) {
        producers.emplace_back([&q, i] {
            for (int j = 0; j < per; ++j) q.push(i * per + j);
        });
    }

    atomic<bool> stop{false};
    mutex outMtx;
    vector<int> consumed;
    consumed.reserve(total);

    vector<thread> consumers;
    for (int i = 0; i < 4; ++i) {
        consumers.emplace_back([&] {
            int v;
            while (true) {
                if (q.tryPop(v, chrono::milliseconds(50))) {
                    lock_guard<mutex> lk(outMtx);
                    consumed.push_back(v);
                } else if (stop.load() && q.size() == 0) {
                    return;
                }
            }
        });
    }

    for (auto& t : producers) t.join();
    stop.store(true);
    for (auto& t : consumers) t.join();

    assert((int)consumed.size() == total);
    sort(consumed.begin(), consumed.end());
    consumed.erase(unique(consumed.begin(), consumed.end()), consumed.end());
    assert((int)consumed.size() == total);

    cout << "thread_safe_queue OK" << endl;
    return 0;
}
