"""二分图匹配：最大匹配（Kuhn 增广路）与最小费用完美匹配（匈牙利 KM）。"""

from __future__ import annotations

from typing import List


def kuhn_max_matching(n_left: int, n_right: int, adj: List[List[int]]) -> int:
    """左部 0..n_left-1，右部 0..n_right-1；adj[u] 为左点 u 的右邻点。返回最大匹配数。"""
    match_r = [-1] * n_right

    def dfs(u: int, seen: List[bool]) -> bool:
        for v in adj[u]:
            if seen[v]:
                continue
            seen[v] = True
            if match_r[v] == -1 or dfs(match_r[v], seen):
                match_r[v] = u
                return True
        return False

    cnt = 0
    for u in range(n_left):
        seen = [False] * n_right
        if dfs(u, seen):
            cnt += 1
    return cnt


def hungarian_min_cost(cost: List[List[int]]) -> int:
    """n×n 费用矩阵，求最小费用完美匹配（经典匈牙利，1-indexed 实现）。"""
    n = len(cost)
    inf = 10**18
    u = [0] * (n + 1)
    v = [0] * (n + 1)
    p = [0] * (n + 1)
    way = [0] * (n + 1)
    for i in range(1, n + 1):
        p[0] = i
        j0 = 0
        minv = [inf] * (n + 1)
        used = [False] * (n + 1)
        while True:
            used[j0] = True
            i0 = p[j0]
            delta = inf
            j1 = 0
            for j in range(1, n + 1):
                if not used[j]:
                    cur = cost[i0 - 1][j - 1] - u[i0] - v[j]
                    if cur < minv[j]:
                        minv[j] = cur
                        way[j] = j0
                    if minv[j] < delta:
                        delta = minv[j]
                        j1 = j
            for j in range(n + 1):
                if used[j]:
                    u[p[j]] += delta
                    v[j] -= delta
                else:
                    minv[j] -= delta
            j0 = j1
            if p[j0] == 0:
                break
        while True:
            j1 = way[j0]
            p[j0] = p[j1]
            j0 = j1
            if j0 == 0:
                break
    return -v[0]


if __name__ == "__main__":
    adj = [[0, 1], [0, 2], [1, 3]]
    assert kuhn_max_matching(3, 4, adj) == 3

    cm = [
        [4, 1, 3],
        [2, 0, 5],
        [3, 2, 2],
    ]
    assert hungarian_min_cost(cm) == 5  # 1+0+2 等组合
    assert kuhn_max_matching(3, 3, [[], [], []]) == 0
    print("bipartite_matching OK")
