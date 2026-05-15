"""常见排序算法演示（教学用，部分为副本排序）。"""

from __future__ import annotations
from collections import deque


def bubble_sort(a: list[int]) -> list[int]:
    a = a[:]
    n = len(a)
    for i in range(n):
        swapped = False
        for j in range(0, n - 1 - i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swapped = True
        if not swapped:
            break
    return a


def selection_sort(a: list[int]) -> list[int]:
    a = a[:]
    n = len(a)
    for i in range(n):
        m = i
        for j in range(i + 1, n):
            if a[j] < a[m]:
                m = j
        a[i], a[m] = a[m], a[i]
    return a


def insertion_sort(a: list[int]) -> list[int]:
    a = a[:]
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
    return a


def merge_sort(a: list[int]) -> list[int]:
    if len(a) <= 1:
        return a[:]
    m = len(a) // 2
    left = merge_sort(a[:m])
    right = merge_sort(a[m:])
    return _merge(left, right)


def _merge(left: list[int], right: list[int]) -> list[int]:
    i = j = 0
    out: list[int] = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            out.append(left[i])
            i += 1
        else:
            out.append(right[j])
            j += 1
    out.extend(left[i:])
    out.extend(right[j:])
    return out


def quick_sort_inplace(a: list[int], lo: int = 0, hi: int | None = None) -> None:
    if hi is None:
        hi = len(a) - 1
    if lo >= hi:
        return
    p = _partition(a, lo, hi)
    quick_sort_inplace(a, lo, p - 1)
    quick_sort_inplace(a, p + 1, hi)


def _partition(a: list[int], lo: int, hi: int) -> int:
    pivot = a[hi]
    i = lo
    for j in range(lo, hi):
        if a[j] <= pivot:
            a[i], a[j] = a[j], a[i]
            i += 1
    a[i], a[hi] = a[hi], a[i]
    return i


def heap_sort(a: list[int]) -> list[int]:
    a = a[:]
    n = len(a)

    def sift_down(start: int, end: int) -> None:
        while True:
            l = 2 * start + 1
            r = l + 1
            m = start
            if l < end and a[l] > a[m]:
                m = l
            if r < end and a[r] > a[m]:
                m = r
            if m == start:
                break
            a[start], a[m] = a[m], a[start]
            start = m

    for i in range(n // 2 - 1, -1, -1):
        sift_down(i, n)
    for end in range(n - 1, 0, -1):
        a[0], a[end] = a[end], a[0]
        sift_down(0, end)
    return a


def counting_sort_nonnegative(a: list[int]) -> list[int]:
    if not a:
        return []
    mx = max(a)
    c = [0] * (mx + 1)
    for x in a:
        c[x] += 1
    out: list[int] = []
    for i, k in enumerate(c):
        out.extend([i] * k)
    return out


def radix_sort_nonneg(a: list[int]) -> list[int]:
    if not a:
        return []
    mx = max(a)
    exp = 1
    a = a[:]
    while mx // exp > 0:
        buckets: list[deque[int]] = [deque() for _ in range(10)]
        for x in a:
            buckets[(x // exp) % 10].append(x)
        a.clear()
        for b in buckets:
            a.extend(b)
        exp *= 10
    return a


def bucket_sort_unit_interval(a: list[float]) -> list[float]:
    """值域约在 [0,1) 的浮点。"""
    n = len(a)
    if n <= 1:
        return a[:]
    buckets: list[list[float]] = [[] for _ in range(n)]
    for x in a:
        bi = min(int(n * x), n - 1)
        buckets[bi].append(x)
    for b in buckets:
        b.sort()
    out: list[float] = []
    for b in buckets:
        out.extend(b)
    return out


if __name__ == "__main__":
    sample = [5, 2, 8, 1, 9, 3]
    empty: list[int] = []
    assert bubble_sort(sample) == sorted(sample)
    assert selection_sort(sample) == sorted(sample)
    assert insertion_sort(sample) == sorted(sample)
    assert bubble_sort(empty) == []
    assert selection_sort([1]) == [1]
    assert merge_sort(sample) == sorted(sample)
    t = sample[:]
    quick_sort_inplace(t)
    assert t == sorted(sample)
    assert heap_sort(sample) == sorted(sample)
    assert counting_sort_nonnegative([3, 0, 2, 2, 1]) == [0, 1, 2, 2, 3]
    assert counting_sort_nonnegative([]) == []
    assert radix_sort_nonneg([170, 45, 75, 90, 2, 802]) == sorted([170, 45, 75, 90, 2, 802])
    assert bucket_sort_unit_interval([0.9, 0.1, 0.4, 0.35]) == sorted([0.9, 0.1, 0.4, 0.35])
    print("sorting OK")
