#include <alg_std.hpp>
#include <cassert>
using namespace std;

int length_of_lis(vector<int> nums) {
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }
    return (int)tails.size();
}

int longest_common_subsequence(const string& a, const string& b) {
    int na = (int)a.size(), nb = (int)b.size();
    vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 0));
    for (int i = 1; i <= na; ++i)
        for (int j = 1; j <= nb; ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[na][nb];
}

int edit_distance(const string& a, const string& b) {
    int na = (int)a.size(), nb = (int)b.size();
    vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 0));
    for (int i = 0; i <= na; ++i) dp[i][0] = i;
    for (int j = 0; j <= nb; ++j) dp[0][j] = j;
    for (int i = 1; i <= na; ++i)
        for (int j = 1; j <= nb; ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    return dp[na][nb];
}

int house_robber(const vector<int>& nums) {
    long long p2 = 0, p1 = 0;
    for (int x : nums) {
        long long cur = max(p1, p2 + x);
        p2 = p1;
        p1 = cur;
    }
    return (int)p1;
}

int main() {
    assert(length_of_lis({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(longest_common_subsequence("abcde", "ace") == 3);
    assert(edit_distance("horse", "ros") == 3);
    assert(house_robber({2, 7, 9, 3, 1}) == 12);
    cout << "linear_dp OK" << endl;
    return 0;
}
