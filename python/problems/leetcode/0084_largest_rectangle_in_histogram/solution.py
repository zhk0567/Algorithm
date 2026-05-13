"""LeetCode 84: Largest Rectangle in Histogram."""

from __future__ import annotations


class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
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


if __name__ == "__main__":
    assert Solution().largestRectangleArea([2, 1, 5, 6, 2, 3]) == 10
    assert Solution().largestRectangleArea([2, 4]) == 4
    assert Solution().largestRectangleArea([]) == 0
    print("0084 OK")
