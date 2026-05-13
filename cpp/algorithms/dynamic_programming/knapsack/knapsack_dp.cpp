#include <bits/stdc++.h>
using namespace std;

int knapsack01(const vector<int>& w, const vector<int>& v, int cap) {
    vector<int> dp(cap + 1, 0);
    for (int i = 0; i < (int)w.size(); ++i)
        for (int x = cap; x >= w[i]; --x) dp[x] = max(dp[x], dp[x - w[i]] + v[i]);
    return dp[cap];
}

int knapsack_unbounded(const vector<int>& w, const vector<int>& v, int cap) {
    vector<int> dp(cap + 1, 0);
    for (int x = 1; x <= cap; ++x)
        for (int i = 0; i < (int)w.size(); ++i)
            if (x >= w[i]) dp[x] = max(dp[x], dp[x - w[i]] + v[i]);
    return dp[cap];
}

int main() {
    vector<int> w{1, 2, 3}, val{6, 10, 12};
    assert(knapsack01(w, val, 5) == 22);
    assert(knapsack_unbounded({1, 3, 4}, {15, 50, 60}, 8) == 130);
    cout << "knapsack_dp OK" << endl;
    return 0;
}
