"""LeetCode 55: Jump Game."""

from __future__ import annotations


class Solution:
    def canJump(self, nums: list[int]) -> bool:
        far = 0
        n = len(nums)
        for i in range(n):
            if i > far:
                return False
            far = max(far, i + nums[i])
            if far >= n - 1:
                return True
        return True


if __name__ == "__main__":
    assert Solution().canJump([2, 3, 1, 1, 4])
    assert not Solution().canJump([3, 2, 1, 0, 4])
    assert Solution().canJump([0])
    print("0055 OK")
