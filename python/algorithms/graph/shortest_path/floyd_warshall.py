"""Floyd–Warshall 全源最短路（可有负权；可判负环）。"""

from __future__ import annotations

from typing import List, Optional, Tuple


def floyd_warshall(n: int, edges: List[Tuple[int, int, int]]) -> Optional[List[List[int]]]:
    """有向边 (u, v, w)。无负环时返回 dist 矩阵；存在负环则返回 None。"""
    inf = 10**15
    dist = [[inf] * n for _ in range(n)]
    for i in range(n):
        dist[i][i] = 0
    for u, v, w in edges:
        dist[u][v] = min(dist[u][v], w)

    for k in range(n):
        for i in range(n):
            di = dist[i][k]
            if di == inf:
                continue
            row = dist[i]
            dk = dist[k]
            for j in range(n):
                w = di + dk[j]
                if w < row[j]:
                    row[j] = w

    for i in range(n):
        if dist[i][i] < 0:
            return None
    return dist


if __name__ == "__main__":
    e = [(0, 1, 2), (1, 2, 1), (0, 2, 5)]
    d = floyd_warshall(3, e)
    assert d is not None
    assert d[0] == [0, 2, 3]
    assert d[1][2] == 1

    neg = [(0, 1, 1), (1, 2, -2), (2, 0, -1)]
    assert floyd_warshall(3, neg) is None
    assert floyd_warshall(1, []) == [[0]]
    d2 = floyd_warshall(2, [])
    assert d2 is not None and d2[0][1] == 10**15
    print("floyd_warshall OK")
