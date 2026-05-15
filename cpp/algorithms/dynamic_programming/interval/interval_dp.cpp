#include <bits/stdc++.h>
#include <cassert>
using namespace std;

long long matrix_chain_order(const vector<int>& p) {
    int n = (int)p.size() - 1;
    if (n <= 0) return 0;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int len = 2; len <= n; ++len)
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX / 4;
            for (int k = i; k < j; ++k) {
                long long cost = dp[i][k] + dp[k + 1][j] + 1LL * p[i] * p[k + 1] * p[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    return dp[0][n - 1];
}

int main() {
    assert(matrix_chain_order({10, 20, 30, 40}) == 1LL * 10 * 20 * 30 + 1LL * 10 * 30 * 40);
    assert(matrix_chain_order({10}) == 0);
    cout << "interval_dp OK" << endl;
    return 0;
}
