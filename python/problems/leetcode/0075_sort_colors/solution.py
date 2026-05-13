"""LeetCode 75: Sort Colors."""

from __future__ import annotations


class Solution:
    def sortColors(self, nums: list[int]) -> None:
        l = 0
        r = len(nums) - 1
        i = 0
        while i <= r:
            if nums[i] == 0:
                nums[l], nums[i] = nums[i], nums[l]
                l += 1
                i += 1
            elif nums[i] == 2:
                nums[r], nums[i] = nums[i], nums[r]
                r -= 1
            else:
                i += 1


if __name__ == "__main__":
    a = [2, 0, 2, 1, 1, 0]
    Solution().sortColors(a)
    assert a == [0, 0, 1, 1, 2, 2]
    b = [2, 0, 1]
    Solution().sortColors(b)
    assert b == [0, 1, 2]
    print("0075 OK")
