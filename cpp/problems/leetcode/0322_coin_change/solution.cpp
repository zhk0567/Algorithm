// LeetCode 322
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int x = 1; x <= amount; ++x)
            for (int c : coins)
                if (c <= x && dp[x - c] + 1 < dp[x])
                    dp[x] = dp[x - c] + 1;
        return dp[amount] == INF ? -1 : dp[amount];
    }
};

int main() {
    vector<int> a{1, 2, 5};
    assert(Solution().coinChange(a, 11) == 3);
    vector<int> b{2};
    assert(Solution().coinChange(b, 3) == -1);
    vector<int> c{1};
    assert(Solution().coinChange(c, 0) == 0);
    cout << "0322 OK" << endl;
    return 0;
}
