"""LeetCode 3: Longest Substring Without Repeating Characters."""

from __future__ import annotations


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last: dict[str, int] = {}
        lo = 0
        best = 0
        for hi, ch in enumerate(s):
            if ch in last and last[ch] >= lo:
                lo = last[ch] + 1
            last[ch] = hi
            best = max(best, hi - lo + 1)
        return best


if __name__ == "__main__":
    assert Solution().lengthOfLongestSubstring("abcabcbb") == 3
    assert Solution().lengthOfLongestSubstring("bbbbb") == 1
    assert Solution().lengthOfLongestSubstring("pwwkew") == 3
    print("0003 OK")
