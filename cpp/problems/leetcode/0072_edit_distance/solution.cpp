// LeetCode 72
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size(), n = (int)word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        return dp[m][n];
    }
};

int main() {
    assert(Solution().minDistance("horse", "ros") == 3);
    assert(Solution().minDistance("intention", "execution") == 5);
    assert(Solution().minDistance("", "abc") == 3);
    cout << "0072 OK" << endl;
    return 0;
}
