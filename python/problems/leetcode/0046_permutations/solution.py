"""LeetCode 46: Permutations."""

from __future__ import annotations


class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        n = len(nums)
        res: list[list[int]] = []
        path: list[int] = []
        used = [False] * n

        def bt() -> None:
            if len(path) == n:
                res.append(path.copy())
                return
            for i in range(n):
                if used[i]:
                    continue
                used[i] = True
                path.append(nums[i])
                bt()
                path.pop()
                used[i] = False

        bt()
        return res


if __name__ == "__main__":
    out = Solution().permute([1, 2, 3])
    expect = {
        (1, 2, 3), (1, 3, 2), (2, 1, 3),
        (2, 3, 1), (3, 1, 2), (3, 2, 1),
    }
    assert {tuple(p) for p in out} == expect
    print("0046 OK")
