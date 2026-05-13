"""LeetCode 27: Remove Element."""

from __future__ import annotations


class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        w = 0
        for x in nums:
            if x != val:
                nums[w] = x
                w += 1
        return w


if __name__ == "__main__":
    a = [3, 2, 2, 3]
    k = Solution().removeElement(a, 3)
    assert k == 2 and sorted(a[:k]) == [2, 2]
    b = [0, 1, 2, 2, 3, 0, 4, 2]
    k2 = Solution().removeElement(b, 2)
    assert k2 == 5 and sorted(b[:k2]) == [0, 0, 1, 3, 4]
    print("0027 OK")
