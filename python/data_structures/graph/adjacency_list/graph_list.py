"""邻接表图：DFS / BFS 演示。"""

from __future__ import annotations
from collections import deque


class GraphList:
    def __init__(self, n: int, directed: bool = False) -> None:
        self.n = n
        self.directed = directed
        self.adj: list[list[tuple[int, int]]] = [[] for _ in range(n)]

    def add_edge(self, u: int, v: int, w: int = 1) -> None:
        self.adj[u].append((v, w))
        if not self.directed:
            self.adj[v].append((u, w))

    def dfs_order(self, start: int) -> list[int]:
        seen = [False] * self.n
        out: list[int] = []

        def dfs(u: int) -> None:
            seen[u] = True
            out.append(u)
            for v, _w in self.adj[u]:
                if not seen[v]:
                    dfs(v)

        dfs(start)
        return out

    def bfs_order(self, start: int) -> list[int]:
        seen = [False] * self.n
        q: deque[int] = deque([start])
        seen[start] = True
        out: list[int] = []
        while q:
            u = q.popleft()
            out.append(u)
            for v, _w in self.adj[u]:
                if not seen[v]:
                    seen[v] = True
                    q.append(v)
        return out


if __name__ == "__main__":
    g = GraphList(4, directed=False)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    assert g.dfs_order(0) == [0, 1, 3, 2]
    assert g.bfs_order(0) == [0, 1, 2, 3]
    print("GraphList OK")
