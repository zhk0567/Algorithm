"""邻接矩阵（无权/权值）。"""

from __future__ import annotations


class GraphMatrix:
    INF = 10**9

    def __init__(self, n: int, directed: bool = False) -> None:
        self.n = n
        self.directed = directed
        self.mat = [[0] * n for _ in range(n)]

    def add_edge(self, u: int, v: int, w: int = 1) -> None:
        self.mat[u][v] = w
        if not self.directed:
            self.mat[v][u] = w

    def has_edge(self, u: int, v: int) -> bool:
        return self.mat[u][v] != 0

    def neighbors(self, u: int) -> list[int]:
        return [v for v in range(self.n) if self.mat[u][v] != 0]


if __name__ == "__main__":
    g = GraphMatrix(3)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    assert g.has_edge(0, 1) and g.has_edge(1, 0)
    assert g.neighbors(0) == [1]
    print("GraphMatrix OK")
