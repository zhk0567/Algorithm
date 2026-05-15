"""Prim 最小生成树（邻接表 + 小根堆）。"""

from __future__ import annotations

import heapq
from typing import List, Tuple


def prim(n: int, edges: List[Tuple[int, int, int]]) -> int:
    """edges: (u, v, w) 无向；返回 MST 边权和。要求图连通。"""
    if n <= 1:
        return 0
    g: List[List[Tuple[int, int]]] = [[] for _ in range(n)]
    for u, v, w in edges:
        g[u].append((v, w))
        g[v].append((u, w))

    visited = [False] * n
    heap: List[Tuple[int, int]] = [(0, 0)]
    total = 0
    taken = 0

    while heap and taken < n:
        w, u = heapq.heappop(heap)
        if visited[u]:
            continue
        visited[u] = True
        total += w
        taken += 1
        for v, wt in g[u]:
            if not visited[v]:
                heapq.heappush(heap, (wt, v))
    if taken < n:
        raise ValueError("graph is not connected")
    return total


if __name__ == "__main__":
    e = [(0, 1, 4), (1, 2, 3), (0, 2, 2)]
    assert prim(3, e) == 5
    assert prim(1, []) == 0
    try:
        prim(2, [])
        raise AssertionError("expected ValueError")
    except ValueError:
        pass
    print("prim OK")
