"""LeetCode 62: Unique Paths."""

from __future__ import annotations


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row = [1] * n
        for _ in range(1, m):
            for j in range(1, n):
                row[j] += row[j - 1]
        return row[-1]


if __name__ == "__main__":
    assert Solution().uniquePaths(3, 7) == 28
    assert Solution().uniquePaths(3, 2) == 3
    assert Solution().uniquePaths(1, 1) == 1
    print("0062 OK")
