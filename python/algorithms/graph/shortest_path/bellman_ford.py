"""Bellman–Ford 单源最短路（可有负权边；可判负环）。"""

from __future__ import annotations

from typing import List, Optional, Tuple


def bellman_ford(
    n: int,
    edges: List[Tuple[int, int, int]],
    src: int,
) -> Optional[List[int]]:
    """有向边 (u, v, w)。无负环时返回 dist；从 src 可达负环则返回 None。"""
    inf = 10**18
    dist = [inf] * n
    dist[src] = 0
    for _ in range(n - 1):
        updated = False
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break
    for u, v, w in edges:
        if dist[u] != inf and dist[u] + w < dist[v]:
            return None
    return dist


if __name__ == "__main__":
    e = [(0, 1, 4), (0, 2, 5), (1, 2, -2)]
    d = bellman_ford(3, e, 0)
    assert d == [0, 4, 2]

    neg = [(0, 1, 1), (1, 2, -1), (2, 0, -1)]
    assert bellman_ford(3, neg, 0) is None
    assert bellman_ford(1, [], 0) == [0]
    inf = 10**18
    assert bellman_ford(3, [(0, 1, 1)], 0) == [0, 1, inf]
    print("bellman_ford OK")
