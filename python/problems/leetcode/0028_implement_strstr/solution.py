"""LeetCode 28: Implement strStr() (KMP)."""

from __future__ import annotations


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        m = len(needle)
        nxt = [0] * m
        k = 0
        for i in range(1, m):
            while k > 0 and needle[k] != needle[i]:
                k = nxt[k - 1]
            if needle[k] == needle[i]:
                k += 1
            nxt[i] = k
        k = 0
        for i, ch in enumerate(haystack):
            while k > 0 and needle[k] != ch:
                k = nxt[k - 1]
            if needle[k] == ch:
                k += 1
            if k == m:
                return i - m + 1
        return -1


if __name__ == "__main__":
    assert Solution().strStr("sadbutsad", "sad") == 0
    assert Solution().strStr("leetcode", "leeto") == -1
    assert Solution().strStr("aaa", "aa") == 0
    assert Solution().strStr("", "") == 0
    print("0028 OK")
