"""LeetCode 8: String to Integer (atoi)."""

from __future__ import annotations

INT_MIN, INT_MAX = -(2**31), 2**31 - 1


class Solution:
    def myAtoi(self, s: str) -> int:
        i, n = 0, len(s)
        while i < n and s[i] == " ":
            i += 1
        if i == n:
            return 0
        sign = 1
        if s[i] in "+-":
            if s[i] == "-":
                sign = -1
            i += 1
        x = 0
        while i < n and s[i].isdigit():
            x = x * 10 + ord(s[i]) - 48
            if sign * x > INT_MAX:
                return INT_MAX
            if sign * x < INT_MIN:
                return INT_MIN
            i += 1
        return sign * x


if __name__ == "__main__":
    assert Solution().myAtoi("42") == 42
    assert Solution().myAtoi("   -42") == -42
    assert Solution().myAtoi("4193 with words") == 4193
    assert Solution().myAtoi("words and 987") == 0
    assert Solution().myAtoi("-91283472332") == INT_MIN
    assert Solution().myAtoi("+1") == 1
    print("0008 OK")
