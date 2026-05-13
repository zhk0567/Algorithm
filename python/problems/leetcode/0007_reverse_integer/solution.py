"""LeetCode 7: Reverse Integer."""

from __future__ import annotations

INT_MIN, INT_MAX = -(2**31), 2**31 - 1


class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        x = abs(x)
        rev = 0
        while x:
            pop = x % 10
            x //= 10
            if rev > INT_MAX // 10 or (rev == INT_MAX // 10 and pop > INT_MAX % 10):
                return 0
            rev = rev * 10 + pop
        rev *= sign
        if rev < INT_MIN or rev > INT_MAX:
            return 0
        return rev


if __name__ == "__main__":
    assert Solution().reverse(123) == 321
    assert Solution().reverse(-123) == -321
    assert Solution().reverse(120) == 21
    assert Solution().reverse(1534236469) == 0
    print("0007 OK")
