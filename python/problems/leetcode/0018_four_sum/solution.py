"""LeetCode 18: 4Sum."""

from __future__ import annotations


class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        nums.sort()
        n = len(nums)
        res: list[list[int]] = []
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                l, r = j + 1, n - 1
                while l < r:
                    s = nums[i] + nums[j] + nums[l] + nums[r]
                    if s < target:
                        l += 1
                    elif s > target:
                        r -= 1
                    else:
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        x, y = nums[l], nums[r]
                        while l < r and nums[l] == x:
                            l += 1
                        while l < r and nums[r] == y:
                            r -= 1
        return res


if __name__ == "__main__":
    out = Solution().fourSum([1, 0, -1, 0, -2, 2], 0)
    assert sorted(map(tuple, out)) == [
        (-2, -1, 1, 2), (-2, 0, 0, 2), (-1, 0, 0, 1),
    ]
    assert Solution().fourSum([2, 2, 2, 2, 2], 8) == [[2, 2, 2, 2]]
    print("0018 OK")
