"""LeetCode 96: Unique Binary Search Trees."""

from __future__ import annotations


class Solution:
    def numTrees(self, n: int) -> int:
        g = [0] * (n + 1)
        g[0] = 1
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                g[i] += g[j - 1] * g[i - j]
        return g[n]


if __name__ == "__main__":
    assert Solution().numTrees(3) == 5
    assert Solution().numTrees(1) == 1
    assert Solution().numTrees(0) == 1
    assert Solution().numTrees(5) == 42
    print("0096 OK")
