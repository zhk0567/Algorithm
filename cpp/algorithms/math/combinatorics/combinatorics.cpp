#include <bits/stdc++.h>
#include <cassert>
using namespace std;

const int MOD = 1000000007;

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Comb {
    int n;
    vector<long long> fac, ifac;
    explicit Comb(int n_) : n(n_), fac(n_ + 1), ifac(n_ + 1) {
        fac[0] = 1;
        for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
        ifac[n] = modpow(fac[n], MOD - 2);
        for (int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i % MOD;
    }
    long long C(int nn, int k) const {
        if (k < 0 || k > nn) return 0;
        return fac[nn] * ifac[k] % MOD * ifac[nn - k] % MOD;
    }
};

int main() {
    Comb cb(100);
    assert(cb.C(5, 2) == 10);
    assert(cb.C(6, 3) == 20);
    cout << "combinatorics OK" << endl;
    return 0;
}
