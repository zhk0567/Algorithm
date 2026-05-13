"""LeetCode 152: Maximum Product Subarray."""

from __future__ import annotations


class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        if not nums:
            return 0
        mx = mn = best = nums[0]
        for x in nums[1:]:
            cand = (x, mx * x, mn * x)
            mx = max(cand)
            mn = min(cand)
            best = max(best, mx)
        return best


if __name__ == "__main__":
    assert Solution().maxProduct([2, 3, -2, 4]) == 6
    assert Solution().maxProduct([-2, 0, -1]) == 0
    assert Solution().maxProduct([-2, 3, -4]) == 24
    print("0152 OK")
