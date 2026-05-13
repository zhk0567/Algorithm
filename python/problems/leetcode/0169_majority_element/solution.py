"""LeetCode 169: Majority Element."""

from __future__ import annotations


class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        cand = 0
        cnt = 0
        for x in nums:
            if cnt == 0:
                cand = x
            cnt += 1 if x == cand else -1
        return cand


if __name__ == "__main__":
    assert Solution().majorityElement([3, 2, 3]) == 3
    assert Solution().majorityElement([2, 2, 1, 1, 1, 2, 2]) == 2
    print("0169 OK")
