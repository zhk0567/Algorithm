"""莫队（离线）：区间不同元素个数。

将询问按左端点所在块排序，块内右端点交替升降序，均摊 O((n+q)·√n) 量级移动指针。
"""

from __future__ import annotations

from collections import defaultdict
from typing import List, Tuple


def mo_distinct_count(arr: List[int], queries: List[Tuple[int, int]]) -> List[int]:
    """queries 为闭区间 [l, r]；返回与 queries 同序的答案列表。"""
    n = len(arr)
    qn = len(queries)
    if qn == 0:
        return []
    b = max(1, int(n**0.5))

    def sort_key(i: int) -> Tuple[int, int]:
        l, r = queries[i]
        bl = l // b
        if bl & 1:
            return (bl, -r)
        return (bl, r)

    order = sorted(range(qn), key=sort_key)
    cnt: defaultdict[int, int] = defaultdict(int)
    cur = 0
    out = [0] * qn

    def add(i: int) -> None:
        nonlocal cur
        x = arr[i]
        cnt[x] += 1
        if cnt[x] == 1:
            cur += 1

    def remove(i: int) -> None:
        nonlocal cur
        x = arr[i]
        cnt[x] -= 1
        if cnt[x] == 0:
            cur -= 1

    L, R = 0, -1
    for qi in order:
        l, r = queries[qi]
        while R < r:
            R += 1
            add(R)
        while R > r:
            remove(R)
            R -= 1
        while L < l:
            remove(L)
            L += 1
        while L > l:
            L -= 1
            add(L)
        out[qi] = cur
    return out


if __name__ == "__main__":
    a = [1, 2, 1, 3, 2, 3, 3]
    assert mo_distinct_count(a, [(0, 6), (1, 4), (4, 4)]) == [3, 3, 1]
    print("mo_algorithm OK")
