"""LeetCode 78: Subsets."""

from __future__ import annotations


class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        res: list[list[int]] = [[]]
        for x in nums:
            res += [r + [x] for r in res]
        return res


if __name__ == "__main__":
    out = Solution().subsets([1, 2, 3])
    expect = {
        (), (1,), (2,), (3,), (1, 2),
        (1, 3), (2, 3), (1, 2, 3),
    }
    assert {tuple(s) for s in out} == expect
    assert Solution().subsets([]) == [[]]
    print("0078 OK")
