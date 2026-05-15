"""LeetCode 600: Non-negative Integers Without Consecutive Ones."""

from __future__ import annotations

from functools import lru_cache


class Solution:
    def findIntegers(self, n: int) -> int:
        s = bin(n)[2:]

        @lru_cache(maxsize=None)
        def dfs(i: int, tight: bool, prev1: bool) -> int:
            if i == len(s):
                return 1
            limit = int(s[i]) if tight else 1
            total = 0
            for d in range(0, limit + 1):
                if d == 1 and prev1:
                    continue
                total += dfs(i + 1, tight and d == limit, d == 1)
            return total

        return dfs(0, True, False)


if __name__ == "__main__":
    assert Solution().findIntegers(5) == 5
    assert Solution().findIntegers(1) == 2
    assert Solution().findIntegers(0) == 1
    assert Solution().findIntegers(10) == 8
    print("0600 OK")
