"""LeetCode 26: Remove Duplicates from Sorted Array."""

from __future__ import annotations


class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if not nums:
            return 0
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[k - 1]:
                nums[k] = nums[i]
                k += 1
        return k


if __name__ == "__main__":
    a = [1, 1, 2]
    k = Solution().removeDuplicates(a)
    assert k == 2 and a[:k] == [1, 2]
    b = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    k2 = Solution().removeDuplicates(b)
    assert k2 == 5 and b[:k2] == [0, 1, 2, 3, 4]
    print("0026 OK")
