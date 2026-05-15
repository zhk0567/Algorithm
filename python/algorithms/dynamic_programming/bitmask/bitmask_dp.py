"""状压 DP：TSP 最短回路（n 小）。"""

from __future__ import annotations


def tsp(dist: list[list[int]]) -> int:
    """dist[i][j] 为有向边权，i==j 为 0，不可达为大数。"""
    n = len(dist)
    if n <= 1:
        return 0
    full = (1 << n) - 1
    inf = 10**15
    dp = [[inf] * n for _ in range(1 << n)]
    dp[1][0] = 0
    for mask in range(1 << n):
        for u in range(n):
            if not (mask >> u) & 1:
                continue
            if dp[mask][u] >= inf:
                continue
            for v in range(n):
                if (mask >> v) & 1:
                    continue
                nmask = mask | (1 << v)
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + dist[u][v])
    best = inf
    for u in range(1, n):
        best = min(best, dp[full][u] + dist[u][0])
    return best


if __name__ == "__main__":
    inf = 10**9
    d = [
        [0, 2, 9, inf],
        [1, 0, 6, 4],
        [15, 7, 0, 8],
        [6, 3, 12, 0],
    ]
    assert tsp(d) == 21
    assert tsp([[0]]) == 0
    print("bitmask_dp OK")
