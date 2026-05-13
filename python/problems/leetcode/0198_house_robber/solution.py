"""LeetCode 198: House Robber."""

from __future__ import annotations


class Solution:
    def rob(self, nums: list[int]) -> int:
        prev = curr = 0
        for x in nums:
            prev, curr = curr, max(curr, prev + x)
        return curr


if __name__ == "__main__":
    assert Solution().rob([1, 2, 3, 1]) == 4
    assert Solution().rob([2, 7, 9, 3, 1]) == 12
    assert Solution().rob([]) == 0
    print("0198 OK")
