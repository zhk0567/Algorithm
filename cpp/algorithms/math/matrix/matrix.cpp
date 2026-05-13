#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007LL;

vector<vector<ll>> mat_mul(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
    int n = (int)a.size(), m = (int)b[0].size(), k = (int)b.size();
    vector<vector<ll>> c(n, vector<ll>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            ll s = 0;
            for (int t = 0; t < k; ++t) s = (s + a[i][t] * b[t][j]) % MOD;
            c[i][j] = s;
        }
    return c;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> base, long long e) {
    int n = (int)base.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (e) {
        if (e & 1) res = mat_mul(res, base);
        base = mat_mul(base, base);
        e >>= 1;
    }
    return res;
}

ll fib(ll n) {
    if (n <= 1) return n;
    vector<vector<ll>> f{{1, 1}, {1, 0}};
    auto p = mat_pow(f, n - 1);
    return p[0][0];
}

int main() {
    assert(fib(10) == 55);
    assert(fib(100) == 687995182);
    cout << "matrix OK" << endl;
    return 0;
}
