"""LeetCode 14: Longest Common Prefix."""

from __future__ import annotations


class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        base = strs[0]
        for i, ch in enumerate(base):
            for s in strs[1:]:
                if i >= len(s) or s[i] != ch:
                    return base[:i]
        return base


if __name__ == "__main__":
    assert Solution().longestCommonPrefix(["flower", "flow", "flight"]) == "fl"
    assert Solution().longestCommonPrefix(["dog", "racecar", "car"]) == ""
    assert Solution().longestCommonPrefix([""]) == ""
    print("0014 OK")
