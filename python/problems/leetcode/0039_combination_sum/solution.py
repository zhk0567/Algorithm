"""LeetCode 39: Combination Sum."""

from __future__ import annotations


class Solution:
    def combinationSum(
        self, candidates: list[int], target: int
    ) -> list[list[int]]:
        candidates.sort()
        res: list[list[int]] = []
        path: list[int] = []

        def bt(start: int, remain: int) -> None:
            if remain == 0:
                res.append(path.copy())
                return
            for i in range(start, len(candidates)):
                c = candidates[i]
                if c > remain:
                    break
                path.append(c)
                bt(i, remain - c)
                path.pop()

        bt(0, target)
        return res


if __name__ == "__main__":
    out = Solution().combinationSum([2, 3, 6, 7], 7)
    assert sorted(map(tuple, out)) == [(2, 2, 3), (7,)]
    out2 = Solution().combinationSum([2, 3, 5], 8)
    assert sorted(map(tuple, out2)) == [(2, 2, 2, 2), (2, 3, 3), (3, 5)]
    print("0039 OK")
