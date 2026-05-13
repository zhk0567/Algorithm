"""LeetCode 70: Climbing Stairs."""

from __future__ import annotations


class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        a, b = 1, 2
        for _ in range(3, n + 1):
            a, b = b, a + b
        return b


if __name__ == "__main__":
    assert Solution().climbStairs(3) == 3
    assert Solution().climbStairs(5) == 8
    print("0070 OK")
