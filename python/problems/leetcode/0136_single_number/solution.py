"""LeetCode 136: Single Number."""

from __future__ import annotations


class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        x = 0
        for n in nums:
            x ^= n
        return x


if __name__ == "__main__":
    assert Solution().singleNumber([2, 2, 1]) == 1
    assert Solution().singleNumber([4, 1, 2, 1, 2]) == 4
    print("0136 OK")
