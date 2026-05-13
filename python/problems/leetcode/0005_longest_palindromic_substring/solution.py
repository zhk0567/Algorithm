"""LeetCode 5: Longest Palindromic Substring."""

from __future__ import annotations


class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        start = end = 0

        def expand(l: int, r: int) -> None:
            nonlocal start, end
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l > end - start:
                    start, end = l, r
                l -= 1
                r += 1

        for i in range(n):
            expand(i, i)
            expand(i, i + 1)
        return s[start : end + 1]


if __name__ == "__main__":
    assert Solution().longestPalindrome("babad") in ("bab", "aba")
    assert Solution().longestPalindrome("cbbd") == "bb"
    print("0005 OK")
