"""LeetCode 85: Maximal Rectangle."""

from __future__ import annotations


def _largest_in_hist(heights: list[int]) -> int:
    h = heights + [0]
    stack: list[int] = []
    best = 0
    for i, x in enumerate(h):
        while stack and h[stack[-1]] > x:
            top = stack.pop()
            left = stack[-1] if stack else -1
            best = max(best, h[top] * (i - left - 1))
        stack.append(i)
    return best


class Solution:
    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        n = len(matrix[0])
        heights = [0] * n
        best = 0
        for row in matrix:
            for j in range(n):
                heights[j] = heights[j] + 1 if row[j] == "1" else 0
            best = max(best, _largest_in_hist(heights))
        return best


if __name__ == "__main__":
    m = [
        ["1", "0", "1", "0", "0"],
        ["1", "0", "1", "1", "1"],
        ["1", "1", "1", "1", "1"],
        ["1", "0", "0", "1", "0"],
    ]
    assert Solution().maximalRectangle(m) == 6
    assert Solution().maximalRectangle([]) == 0
    assert Solution().maximalRectangle([["0"]]) == 0
    assert Solution().maximalRectangle([["1"]]) == 1
    print("0085 OK")
