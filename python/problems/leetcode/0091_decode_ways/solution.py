"""LeetCode 91: Decode Ways."""

from __future__ import annotations


class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == "0":
            return 0
        prev2, prev1 = 1, 1
        for i in range(1, len(s)):
            cur = 0
            if s[i] != "0":
                cur += prev1
            two = int(s[i - 1 : i + 1])
            if 10 <= two <= 26:
                cur += prev2
            prev2, prev1 = prev1, cur
        return prev1


if __name__ == "__main__":
    assert Solution().numDecodings("12") == 2
    assert Solution().numDecodings("226") == 3
    assert Solution().numDecodings("06") == 0
    assert Solution().numDecodings("0") == 0
    assert Solution().numDecodings("10") == 1
    print("0091 OK")
