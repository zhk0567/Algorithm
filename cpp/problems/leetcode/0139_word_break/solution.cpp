// LeetCode 139
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        int max_len = 0;
        for (auto& w : words) max_len = max(max_len, (int)w.size());
        for (int i = 1; i <= n; ++i)
            for (int j = max(0, i - max_len); j < i; ++j)
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
        return dp[n];
    }
};

int main() {
    vector<string> d1{"leet", "code"};
    assert(Solution().wordBreak("leetcode", d1));
    vector<string> d2{"apple", "pen"};
    assert(Solution().wordBreak("applepenapple", d2));
    vector<string> d3{"cats", "dog", "sand", "and", "cat"};
    assert(!Solution().wordBreak("catsandog", d3));
    cout << "0139 OK" << endl;
    return 0;
}
