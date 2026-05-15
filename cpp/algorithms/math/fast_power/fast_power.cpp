// 快速幂：二进制幂与模幂
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

long long fastPow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r *= a;
        a *= a;
        e >>= 1;
    }
    return r;
}

long long modPow(long long a, long long e, long long mod) {
    if (mod == 1) return 0;
    long long r = 1 % mod;
    a %= mod;
    while (e) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    assert(fastPow(2, 10) == 1024);
    assert(fastPow(3, 0) == 1);
    assert(modPow(7, 10, 13) == 4);
    assert(modPow(2, 100, 1'000'000'007LL) == 976371285LL);
    cout << "fast_power OK" << endl;
    return 0;
}
