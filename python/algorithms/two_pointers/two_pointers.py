"""双指针：两数之和（有序）、三数之和个数演示、盛水容器。"""

from __future__ import annotations


def two_sum_sorted(a: list[int], t: int) -> tuple[int, int] | None:
    lo, hi = 0, len(a) - 1
    while lo < hi:
        s = a[lo] + a[hi]
        if s == t:
            return lo, hi
        if s < t:
            lo += 1
        else:
            hi -= 1
    return None


def max_area(height: list[int]) -> int:
    """盛最多水的容器。"""
    lo, hi = 0, len(height) - 1
    best = 0
    while lo < hi:
        w = hi - lo
        best = max(best, w * min(height[lo], height[hi]))
        if height[lo] < height[hi]:
            lo += 1
        else:
            hi -= 1
    return best


if __name__ == "__main__":
    a = [1, 2, 4, 6, 10]
    p = two_sum_sorted(a, 8)
    assert p is not None and a[p[0]] + a[p[1]] == 8
    assert max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
    print("two_pointers OK")
