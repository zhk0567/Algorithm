"""LeetCode 307: Range Sum Query - Mutable."""

from __future__ import annotations


class NumArray:
    """单点修改 + 区间和：树状数组（与 `data_structures/tree/fenwick_tree` 同族）。"""

    def __init__(self, nums: list[int]) -> None:
        self._nums = nums[:]
        self._n = len(nums)
        self._bit = [0] * (self._n + 1)
        for i, v in enumerate(nums):
            self._add(i + 1, v)

    def _add(self, i: int, delta: int) -> None:
        while i <= self._n:
            self._bit[i] += delta
            i += i & -i

    def _prefix(self, i: int) -> int:
        s = 0
        while i > 0:
            s += self._bit[i]
            i -= i & -i
        return s

    def update(self, index: int, val: int) -> None:
        d = val - self._nums[index]
        self._nums[index] = val
        self._add(index + 1, d)

    def sumRange(self, left: int, right: int) -> int:
        return self._prefix(right + 1) - self._prefix(left)


if __name__ == "__main__":
    na = NumArray([1, 3, 5])
    assert na.sumRange(0, 2) == 9
    na.update(1, 2)
    assert na.sumRange(0, 2) == 8
    na2 = NumArray([0])
    assert na2.sumRange(0, 0) == 0
    na2.update(0, 5)
    assert na2.sumRange(0, 0) == 5
    print("0307 OK")
