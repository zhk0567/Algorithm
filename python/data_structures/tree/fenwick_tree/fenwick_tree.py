"""树状数组：单点加、前缀和；附带区间加单点查。"""

from __future__ import annotations


class FenwickTree:
    """单点加、前缀和，0-based 对外接口。"""

    def __init__(self, n: int) -> None:
        self._n = n
        self._bit = [0] * (n + 1)

    def add(self, index: int, delta: int) -> None:
        i = index + 1
        while i <= self._n:
            self._bit[i] += delta
            i += i & -i

    def prefix_sum(self, index: int) -> int:
        """[0, index] 的和。"""
        i = index + 1
        s = 0
        while i > 0:
            s += self._bit[i]
            i -= i & -i
        return s

    def range_sum(self, l: int, r: int) -> int:
        if l == 0:
            return self.prefix_sum(r)
        return self.prefix_sum(r) - self.prefix_sum(l - 1)


class FenwickRUPQ:
    """区间加 v 到 [l,r]，查询下标 i 的值（差分 + BIT）。"""

    def __init__(self, n: int) -> None:
        self._n = n
        self._bit = FenwickTree(n + 2)

    def range_add(self, l: int, r: int, v: int) -> None:
        self._bit.add(l, v)
        if r + 1 < self._n:
            self._bit.add(r + 1, -v)

    def point_query(self, i: int) -> int:
        return self._bit.prefix_sum(i)


if __name__ == "__main__":
    ft = FenwickTree(5)
    for i, v in enumerate([1, 2, 3, 4, 5]):
        ft.add(i, v)
    assert ft.range_sum(1, 3) == 9
    ft1 = FenwickTree(1)
    ft1.add(0, 7)
    assert ft1.prefix_sum(0) == 7
    rupq = FenwickRUPQ(5)
    rupq.range_add(1, 3, 10)
    assert rupq.point_query(0) == 0
    assert rupq.point_query(2) == 10
    print("Fenwick OK")
