"""贪心：活动选择、分数背包。"""

from __future__ import annotations


def activity_selection(intervals: list[tuple[int, int]]) -> int:
    """intervals: (start, end)，最多不相交区间数。"""
    intervals = sorted(intervals, key=lambda x: x[1])
    cnt = 0
    last_end = -10**9
    for s, e in intervals:
        if s >= last_end:
            cnt += 1
            last_end = e
    return cnt


def fractional_knapsack(items: list[tuple[int, int]], capacity: int) -> float:
    """items: (weight, value)，可分割，求最大价值。"""
    ratio = [(v / w, w, v) for w, v in items if w > 0]
    ratio.sort(reverse=True)
    rem = float(capacity)
    total = 0.0
    for _r, w, v in ratio:
        if rem <= 0:
            break
        take = min(rem, w)
        total += take * (v / w)
        rem -= take
    return total


if __name__ == "__main__":
    assert activity_selection([(1, 2), (3, 4), (5, 6), (7, 8)]) == 4
    assert abs(fractional_knapsack([(10, 60), (20, 100), (30, 120)], 50) - 240.0) < 1e-9
    print("greedy OK")
