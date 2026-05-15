"""Kahn 拓扑排序。"""

from __future__ import annotations
from collections import deque


def topological_sort(adj: list[list[int]]) -> list[int] | None:
    n = len(adj)
    indeg = [0] * n
    for u in range(n):
        for v in adj[u]:
            indeg[v] += 1
    q: deque[int] = deque([i for i in range(n) if indeg[i] == 0])
    order: list[int] = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    if len(order) != n:
        return None
    return order


if __name__ == "__main__":
    # 0->1->2, 0->2
    g = [[] for _ in range(3)]
    g[0].extend([1, 2])
    g[1].append(2)
    t = topological_sort(g)
    assert t is not None and t == [0, 1, 2]
    g_cycle = [[1], [0], []]
    assert topological_sort(g_cycle) is None
    assert topological_sort([[]]) == [0]
    print("topological_sort OK")
