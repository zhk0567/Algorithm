"""线段树：区间加 + 区间和。"""

from __future__ import annotations


class SegmentTreeLazy:
    """下标 0..n-1，区间加、区间求和。"""

    def __init__(self, data: list[int]) -> None:
        self._n = len(data)
        self._sum = [0] * (4 * max(1, self._n))
        self._lazy = [0] * (4 * max(1, self._n))
        if self._n:
            self._build(1, 0, self._n - 1, data)

    def _build(self, idx: int, l: int, r: int, data: list[int]) -> None:
        if l == r:
            self._sum[idx] = data[l]
            return
        m = (l + r) // 2
        self._build(idx * 2, l, m, data)
        self._build(idx * 2 + 1, m + 1, r, data)
        self._sum[idx] = self._sum[idx * 2] + self._sum[idx * 2 + 1]

    def _push(self, idx: int, l: int, r: int) -> None:
        if self._lazy[idx] == 0 or l == r:
            return
        m = (l + r) // 2
        for child in (idx * 2, idx * 2 + 1):
            self._lazy[child] += self._lazy[idx]
        self._sum[idx * 2] += self._lazy[idx] * (m - l + 1)
        self._sum[idx * 2 + 1] += self._lazy[idx] * (r - m)
        self._lazy[idx] = 0

    def range_add(self, ql: int, qr: int, val: int) -> None:
        self._range_add(1, 0, self._n - 1, ql, qr, val)

    def _range_add(self, idx: int, l: int, r: int, ql: int, qr: int, val: int) -> None:
        if ql > r or qr < l:
            return
        if ql <= l and r <= qr:
            self._lazy[idx] += val
            self._sum[idx] += val * (r - l + 1)
            return
        self._push(idx, l, r)
        m = (l + r) // 2
        self._range_add(idx * 2, l, m, ql, qr, val)
        self._range_add(idx * 2 + 1, m + 1, r, ql, qr, val)
        self._sum[idx] = self._sum[idx * 2] + self._sum[idx * 2 + 1]

    def range_sum(self, ql: int, qr: int) -> int:
        return self._range_sum(1, 0, self._n - 1, ql, qr)

    def _range_sum(self, idx: int, l: int, r: int, ql: int, qr: int) -> int:
        if ql > r or qr < l:
            return 0
        if ql <= l and r <= qr:
            return self._sum[idx]
        self._push(idx, l, r)
        m = (l + r) // 2
        return self._range_sum(idx * 2, l, m, ql, qr) + self._range_sum(idx * 2 + 1, m + 1, r, ql, qr)


if __name__ == "__main__":
    st = SegmentTreeLazy([1, 2, 3, 4, 5])
    assert st.range_sum(1, 3) == 9
    st.range_add(1, 3, 10)
    assert st.range_sum(0, 4) == 1 + (2 + 10) + (3 + 10) + (4 + 10) + 5
    print("SegmentTree OK")
