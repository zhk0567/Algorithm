"""线性查找与二分变体。"""

from __future__ import annotations


def linear_search(a: list[int], x: int) -> int:
    for i, v in enumerate(a):
        if v == x:
            return i
    return -1


def binary_search(a: list[int], x: int) -> int:
    """有序 a 中找 x，不存在返回 -1。"""
    lo, hi = 0, len(a) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if a[mid] == x:
            return mid
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


def lower_bound(a: list[int], x: int) -> int:
    """第一个 >= x 的下标（可能 len）。"""
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo


def upper_bound(a: list[int], x: int) -> int:
    """第一个 > x 的下标。"""
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] <= x:
            lo = mid + 1
        else:
            hi = mid
    return lo


def search_rotated(a: list[int], t: int) -> int:
    """无重复元素的旋转有序数组中查找 t。"""
    lo, hi = 0, len(a) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if a[mid] == t:
            return mid
        if a[lo] <= a[mid]:
            if a[lo] <= t < a[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        else:
            if a[mid] < t <= a[hi]:
                lo = mid + 1
            else:
                hi = mid - 1
    return -1


if __name__ == "__main__":
    a = [1, 3, 3, 5, 7]
    assert linear_search(a, 5) == 3
    assert binary_search([1, 2, 4, 8], 4) == 2
    assert lower_bound(a, 3) == 1 and upper_bound(a, 3) == 3
    rot = [4, 5, 6, 7, 0, 1, 2]
    assert search_rotated(rot, 0) == 4
    assert linear_search([], 1) == -1
    assert lower_bound([], 3) == 0 and upper_bound([], 3) == 0
    assert search_rotated([7], 7) == 0
    print("searching OK")
