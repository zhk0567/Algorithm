#include <bits/stdc++.h>
using namespace std;

long long gcd_ll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return abs(a);
}

tuple<long long, long long, long long> extgcd(long long a, long long b) {
    if (!b) return {a, 1, 0};
    auto [g, x1, y1] = extgcd(b, a % b);
    return {g, y1, x1 - (a / b) * y1};
}

long long mod_pow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    a %= mod;
    while (e) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

vector<char> sieve(int n) {
    vector<char> is(n + 1, 1);
    if (n >= 0) is[0] = 0;
    if (n >= 1) is[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (is[i])
            for (int j = i * i; j <= n; j += i) is[j] = 0;
    return is;
}

int main() {
    assert(gcd_ll(54, 24) == 6);
    auto [g, x, y] = extgcd(35LL, 15LL);
    assert(g == 5 && 35 * x + 15 * y == 5);
    assert(mod_pow(7, 10, 13) == 4);
    auto sp = sieve(30);
    int c = accumulate(sp.begin(), sp.end(), 0);
    assert(c == 10);
    cout << "number_theory OK" << endl;
    return 0;
}
