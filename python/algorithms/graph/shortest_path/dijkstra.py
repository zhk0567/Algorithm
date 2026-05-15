"""Dijkstra 最短路。"""

from __future__ import annotations
import heapq


def dijkstra(adj: list[list[tuple[int, int]]], src: int) -> list[int]:
    """非负权图单源最短路；含负权边请用 Bellman–Ford。"""
    n = len(adj)
    for u in range(n):
        for _, w in adj[u]:
            if w < 0:
                raise ValueError("negative edge weight; use Bellman-Ford")
    dist = [10**18] * n
    dist[src] = 0
    pq: list[tuple[int, int]] = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d != dist[u]:
            continue
        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist


if __name__ == "__main__":
    # 0--1 weight2, 0--2 weight5, 1--2 weight1
    g: list[list[tuple[int, int]]] = [[] for _ in range(3)]
    g[0].append((1, 2))
    g[1].append((0, 2))
    g[0].append((2, 5))
    g[2].append((0, 5))
    g[1].append((2, 1))
    g[2].append((1, 1))
    d = dijkstra(g, 0)
    assert d == [0, 2, 3]
    assert dijkstra([[]], 0) == [0]
    g2: list[list[tuple[int, int]]] = [[], [(0, 1)]]
    assert dijkstra(g2, 0)[1] == 10**18
    try:
        dijkstra([[(1, -1)], [(0, -1)]], 0)
        raise AssertionError("expected ValueError")
    except ValueError:
        pass
    print("shortest_path OK")
