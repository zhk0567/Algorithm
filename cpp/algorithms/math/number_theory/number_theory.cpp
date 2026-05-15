// 数论：gcd、埃氏筛（模幂与扩欧见 fast_power / extended_gcd）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

long long gcd_ll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return abs(a);
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
    auto sp = sieve(30);
    int c = accumulate(sp.begin(), sp.end(), 0);
    assert(c == 10);
    cout << "number_theory OK" << endl;
    return 0;
}
