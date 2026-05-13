// 令牌桶限流器
#include <bits/stdc++.h>
#include <cassert>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

class TokenBucket {
public:
    TokenBucket(double rate, double capacity)
        : rate_(rate), cap_(capacity), tokens_(capacity), last_(now()) {
        if (rate <= 0 || capacity <= 0) throw invalid_argument("positive required");
    }

    bool tryAcquire(double n = 1.0) {
        lock_guard<mutex> lk(mtx_);
        refill();
        if (tokens_ >= n) {
            tokens_ -= n;
            return true;
        }
        return false;
    }

    bool acquire(double n, chrono::milliseconds timeout) {
        if (n > cap_) throw invalid_argument("n exceeds capacity");
        auto deadline = chrono::steady_clock::now() + timeout;
        while (true) {
            double wait_sec;
            {
                lock_guard<mutex> lk(mtx_);
                refill();
                if (tokens_ >= n) {
                    tokens_ -= n;
                    return true;
                }
                wait_sec = (n - tokens_) / rate_;
            }
            auto remain = deadline - chrono::steady_clock::now();
            if (remain <= chrono::steady_clock::duration::zero()) return false;
            auto sleep_for = chrono::duration_cast<chrono::milliseconds>(
                chrono::duration<double>(wait_sec));
            if (sleep_for > chrono::duration_cast<chrono::milliseconds>(remain)) {
                sleep_for = chrono::duration_cast<chrono::milliseconds>(remain);
            }
            this_thread::sleep_for(sleep_for);
        }
    }

private:
    double rate_;
    double cap_;
    double tokens_;
    chrono::steady_clock::time_point last_;
    mutex mtx_;

    static chrono::steady_clock::time_point now() {
        return chrono::steady_clock::now();
    }

    void refill() {
        auto cur = now();
        double dt = chrono::duration<double>(cur - last_).count();
        if (dt > 0) {
            tokens_ = min(cap_, tokens_ + dt * rate_);
            last_ = cur;
        }
    }
};

int main() {
    TokenBucket bucket(5.0, 5.0);
    int granted = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 12; ++i) {
        if (bucket.tryAcquire()) ++granted;
        this_thread::sleep_for(chrono::milliseconds(90));
    }
    double dur = chrono::duration<double>(chrono::steady_clock::now() - start).count();
    int upper = (int)(5 + 5.0 * dur) + 1;
    assert(granted >= 5 && granted <= upper);

    TokenBucket drain(10.0, 2.0);
    assert(drain.tryAcquire(2));
    auto t0 = chrono::steady_clock::now();
    assert(drain.acquire(1, chrono::milliseconds(1000)));
    double waited = chrono::duration<double>(chrono::steady_clock::now() - t0).count();
    assert(waited >= 0.05);

    cout << "rate_limiter OK" << endl;
    return 0;
}
