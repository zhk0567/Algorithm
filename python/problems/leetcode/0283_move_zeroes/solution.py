"""LeetCode 283: Move Zeroes."""

from __future__ import annotations


class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        w = 0
        for x in nums:
            if x != 0:
                nums[w] = x
                w += 1
        for i in range(w, len(nums)):
            nums[i] = 0


if __name__ == "__main__":
    a = [0, 1, 0, 3, 12]
    Solution().moveZeroes(a)
    assert a == [1, 3, 12, 0, 0]
    b = [0]
    Solution().moveZeroes(b)
    assert b == [0]
    print("0283 OK")
