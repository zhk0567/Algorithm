"""LeetCode 406: Queue Reconstruction by Height."""

from __future__ import annotations


class Solution:
    def reconstructQueue(self, people: list[list[int]]) -> list[list[int]]:
        people.sort(key=lambda p: (-p[0], p[1]))
        res: list[list[int]] = []
        for p in people:
            res.insert(p[1], p)
        return res


if __name__ == "__main__":
    out = Solution().reconstructQueue(
        [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
    )
    assert out == [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
    print("0406 OK")
