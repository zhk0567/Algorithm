"""0-1 背包与完全背包。"""

from __future__ import annotations


def knapsack_01(weights: list[int], values: list[int], cap: int) -> int:
    dp = [0] * (cap + 1)
    for w, v in zip(weights, values):
        for x in range(cap, w - 1, -1):
            dp[x] = max(dp[x], dp[x - w] + v)
    return dp[cap]


def knapsack_unbounded(weights: list[int], values: list[int], cap: int) -> int:
    dp = [0] * (cap + 1)
    for x in range(1, cap + 1):
        for w, v in zip(weights, values):
            if x >= w:
                dp[x] = max(dp[x], dp[x - w] + v)
    return dp[cap]


if __name__ == "__main__":
    w = [1, 2, 3]
    val = [6, 10, 12]
    assert knapsack_01(w, val, 5) == 22
    assert knapsack_unbounded([1, 3, 4], [15, 50, 60], 8) == 130
    assert knapsack_01([], [], 0) == 0
    print("knapsack_dp OK")
