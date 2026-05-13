"""LeetCode 15: 3Sum."""

from __future__ import annotations


class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        n = len(nums)
        res: list[list[int]] = []
        for i in range(n):
            if i and nums[i] == nums[i - 1]:
                continue
            if nums[i] > 0:
                break
            l, r = i + 1, n - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s < 0:
                    l += 1
                elif s > 0:
                    r -= 1
                else:
                    res.append([nums[i], nums[l], nums[r]])
                    x, y = nums[l], nums[r]
                    while l < r and nums[l] == x:
                        l += 1
                    while l < r and nums[r] == y:
                        r -= 1
        return res


if __name__ == "__main__":
    out = Solution().threeSum([-1, 0, 1, 2, -1, -4])
    out_set = {tuple(t) for t in out}
    assert out_set == {(-1, -1, 2), (-1, 0, 1)}
    print("0015 OK")
