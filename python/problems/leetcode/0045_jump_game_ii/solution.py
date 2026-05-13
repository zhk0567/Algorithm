"""LeetCode 45: Jump Game II."""

from __future__ import annotations


class Solution:
    def jump(self, nums: list[int]) -> int:
        steps = end = far = 0
        for i in range(len(nums) - 1):
            far = max(far, i + nums[i])
            if i == end:
                steps += 1
                end = far
        return steps


if __name__ == "__main__":
    assert Solution().jump([2, 3, 1, 1, 4]) == 2
    assert Solution().jump([2, 3, 0, 1, 4]) == 2
    assert Solution().jump([0]) == 0
    print("0045 OK")
