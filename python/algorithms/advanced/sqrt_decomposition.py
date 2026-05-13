"""分块（Sqrt decomposition）：区间和查询 + 单点加。"""

from __future__ import annotations
import math


class SqrtDecomposition:
    """将数组分块，块内维护元素和；单点加 O(1)，区间和 O(√n)。"""

    def __init__(self, a: list[int]) -> None:
        self.a = a[:]
        self.n = len(self.a)
        self.b = max(1, int(math.sqrt(self.n)))
        self._build_blocks()

    def _build_blocks(self) -> None:
        self.blk: list[int] = []
        for i in range(0, self.n, self.b):
            self.blk.append(sum(self.a[i : i + self.b]))

    def _id(self, i: int) -> int:
        return i // self.b

    def point_add(self, i: int, delta: int) -> None:
        self.a[i] += delta
        self.blk[self._id(i)] += delta

    def range_sum(self, l: int, r: int) -> int:
        s = 0
        if self._id(l) == self._id(r):
            return sum(self.a[l : r + 1])
        while l <= r and l % self.b != 0:
            s += self.a[l]
            l += 1
        while l <= r and (r + 1) % self.b != 0:
            s += self.a[r]
            r -= 1
        while l <= r:
            s += self.blk[self._id(l)]
            l += self.b
        return s


if __name__ == "__main__":
    sd = SqrtDecomposition([1, 2, 3, 4, 5])
    assert sd.range_sum(0, 4) == 15
    sd.point_add(2, 10)
    assert sd.range_sum(0, 4) == 25
    assert sd.range_sum(1, 3) == 2 + 13 + 4
    print("advanced OK")
