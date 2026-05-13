"""LeetCode 416: Partition Equal Subset Sum."""

from __future__ import annotations


class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        target = total // 2
        dp = [False] * (target + 1)
        dp[0] = True
        for x in nums:
            for s in range(target, x - 1, -1):
                if dp[s - x]:
                    dp[s] = True
        return dp[target]


if __name__ == "__main__":
    assert Solution().canPartition([1, 5, 11, 5])
    assert not Solution().canPartition([1, 2, 3, 5])
    assert Solution().canPartition([2, 2, 2, 2])
    print("0416 OK")
