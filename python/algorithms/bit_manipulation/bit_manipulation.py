"""位运算：lowbit、popcount、子集枚举。"""

from __future__ import annotations


def lowbit(x: int) -> int:
    return x & -x


def popcount(x: int) -> int:
    c = 0
    while x:
        x &= x - 1
        c += 1
    return c


def subsets_of_mask(m: int) -> list[int]:
    out: list[int] = []
    s = m
    while True:
        out.append(s)
        if s == 0:
            break
        s = (s - 1) & m
    return out


if __name__ == "__main__":
    assert lowbit(12) == 4
    assert popcount(0b1011) == 3
    assert set(subsets_of_mask(0b101)) == {0b101, 0b100, 0b001, 0b000}
    print("bit_manipulation OK")
