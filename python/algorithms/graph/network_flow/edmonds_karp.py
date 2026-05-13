"""Edmonds-Karp 最大流。"""

from __future__ import annotations
from collections import deque


def edmonds_karp(cap: list[list[int]], s: int, t: int) -> int:
    n = len(cap)
    flow = 0
    g = [row[:] for row in cap]
    while True:
        parent = [-1] * n
        q: deque[int] = deque([s])
        parent[s] = s
        while q and parent[t] == -1:
            u = q.popleft()
            for v in range(n):
                if parent[v] == -1 and g[u][v] > 0:
                    parent[v] = u
                    q.append(v)
        if parent[t] == -1:
            break
        add = 10**18
        v = t
        while v != s:
            u = parent[v]
            add = min(add, g[u][v])
            v = u
        v = t
        while v != s:
            u = parent[v]
            g[u][v] -= add
            g[v][u] += add
            v = u
        flow += add
    return flow


if __name__ == "__main__":
    # 经典 4 点网络
    inf = 10**9
    cap = [[0] * 4 for _ in range(4)]
    cap[0][1] = 3
    cap[0][2] = 2
    cap[1][2] = 1
    cap[1][3] = 2
    cap[2][3] = 3
    assert edmonds_karp(cap, 0, 3) == 5
    print("network_flow OK")
