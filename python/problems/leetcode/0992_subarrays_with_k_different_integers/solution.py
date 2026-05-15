"""LeetCode 992: Subarrays with K Different Integers."""

from __future__ import annotations


class Solution:
    def subarraysWithKDistinct(self, nums: list[int], k: int) -> int:
        def at_most(k_limit: int) -> int:
            if k_limit < 0:
                return 0
            count: dict[int, int] = {}
            left = 0
            res = 0
            for right, x in enumerate(nums):
                count[x] = count.get(x, 0) + 1
                while len(count) > k_limit:
                    y = nums[left]
                    count[y] -= 1
                    if count[y] == 0:
                        del count[y]
                    left += 1
                res += right - left + 1
            return res

        return at_most(k) - at_most(k - 1)


if __name__ == "__main__":
    assert Solution().subarraysWithKDistinct([1, 2, 1, 2, 3], 2) == 7
    assert Solution().subarraysWithKDistinct([1, 2, 1, 3, 4], 3) == 3
    assert Solution().subarraysWithKDistinct([1, 1, 1], 1) == 6
    print("0992 OK")
