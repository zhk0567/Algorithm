"""LeetCode 10: Regular Expression Matching."""

from __future__ import annotations


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        for j in range(2, n + 1):
            if p[j - 1] == "*":
                dp[0][j] = dp[0][j - 2]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == "*":
                    dp[i][j] = dp[i][j - 2]
                    if p[j - 2] == "." or p[j - 2] == s[i - 1]:
                        dp[i][j] = dp[i][j] or dp[i - 1][j]
                else:
                    if p[j - 1] == "." or p[j - 1] == s[i - 1]:
                        dp[i][j] = dp[i - 1][j - 1]
        return dp[m][n]


if __name__ == "__main__":
    assert not Solution().isMatch("aa", "a")
    assert Solution().isMatch("aa", "a*")
    assert Solution().isMatch("ab", ".*")
    assert Solution().isMatch("aab", "c*a*b")
    assert not Solution().isMatch("mississippi", "mis*is*p*.")
    print("0010 OK")
