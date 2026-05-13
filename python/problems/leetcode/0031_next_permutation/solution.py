"""LeetCode 31: Next Permutation."""

from __future__ import annotations


class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        n = len(nums)
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        l, r = i + 1, n - 1
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1


if __name__ == "__main__":
    a = [1, 2, 3]
    Solution().nextPermutation(a)
    assert a == [1, 3, 2]
    b = [3, 2, 1]
    Solution().nextPermutation(b)
    assert b == [1, 2, 3]
    c = [1, 1, 5]
    Solution().nextPermutation(c)
    assert c == [1, 5, 1]
    print("0031 OK")
