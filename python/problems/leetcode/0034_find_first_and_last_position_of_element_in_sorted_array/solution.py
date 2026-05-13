"""LeetCode 34: Find First and Last Position of Element in Sorted Array."""

from __future__ import annotations

from bisect import bisect_left, bisect_right


class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        l = bisect_left(nums, target)
        r = bisect_right(nums, target) - 1
        if l <= r:
            return [l, r]
        return [-1, -1]


if __name__ == "__main__":
    assert Solution().searchRange([5, 7, 7, 8, 8, 10], 8) == [3, 4]
    assert Solution().searchRange([5, 7, 7, 8, 8, 10], 6) == [-1, -1]
    assert Solution().searchRange([], 0) == [-1, -1]
    print("0034 OK")
