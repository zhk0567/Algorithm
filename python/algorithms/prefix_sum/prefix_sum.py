"""前缀和与差分数组。"""

from __future__ import annotations


def build_prefix(a: list[int]) -> list[int]:
    p = [0] * (len(a) + 1)
    for i, x in enumerate(a):
        p[i + 1] = p[i] + x
    return p


def range_sum(p: list[int], l: int, r: int) -> int:
    return p[r + 1] - p[l]


class DifferenceArray:
    def __init__(self, n: int) -> None:
        self.n = n
        self.d = [0] * (n + 1)

    def range_add(self, l: int, r: int, v: int) -> None:
        self.d[l] += v
        if r + 1 < len(self.d):
            self.d[r + 1] -= v

    def to_array(self) -> list[int]:
        a: list[int] = []
        s = 0
        for i in range(self.n):
            s += self.d[i]
            a.append(s)
        return a


if __name__ == "__main__":
    a = [1, 2, 3, 4]
    p = build_prefix(a)
    assert range_sum(p, 1, 2) == 5
    da = DifferenceArray(5)
    da.range_add(1, 3, 5)
    assert da.to_array() == [0, 5, 5, 5, 0]
    assert build_prefix([]) == [0]
    assert DifferenceArray(0).to_array() == []
    print("prefix_sum OK")
