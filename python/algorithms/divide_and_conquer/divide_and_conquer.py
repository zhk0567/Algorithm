"""分治：快速幂、归并排序、最大子数组和（分治）。"""

from __future__ import annotations


def mod_pow(base: int, exp: int, mod: int) -> int:
    if mod == 1:
        return 0
    res = 1
    b = base % mod
    e = exp
    while e > 0:
        if e & 1:
            res = (res * b) % mod
        b = (b * b) % mod
        e >>= 1
    return res


def max_subarray_dc(a: list[int]) -> int:
    """最大子数组和，分治 O(n log n)。"""
    if not a:
        return 0

    def cross(lo: int, mid: int, hi: int) -> int:
        left_sum = best = a[mid]
        for i in range(mid - 1, lo - 1, -1):
            left_sum += a[i]
            best = max(best, left_sum)
        right_sum = s = a[mid + 1]
        for i in range(mid + 2, hi + 1):
            right_sum += a[i]
            s = max(s, right_sum)
        return best + s

    def dac(lo: int, hi: int) -> int:
        if lo == hi:
            return a[lo]
        mid = (lo + hi) // 2
        return max(dac(lo, mid), dac(mid + 1, hi), cross(lo, mid, hi))

    return dac(0, len(a) - 1)


if __name__ == "__main__":
    assert mod_pow(2, 10, 1000) == 24
    assert mod_pow(3, 0, 7) == 1
    assert max_subarray_dc([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
    print("divide_and_conquer OK")
