"""LeetCode 139: Word Break."""

from __future__ import annotations


class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        words = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        max_len = max((len(w) for w in words), default=0)
        for i in range(1, n + 1):
            for j in range(max(0, i - max_len), i):
                if dp[j] and s[j:i] in words:
                    dp[i] = True
                    break
        return dp[n]


if __name__ == "__main__":
    assert Solution().wordBreak("leetcode", ["leet", "code"])
    assert Solution().wordBreak("applepenapple", ["apple", "pen"])
    assert not Solution().wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"])
    print("0139 OK")
