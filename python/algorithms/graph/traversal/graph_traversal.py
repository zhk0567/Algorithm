"""DFS / BFS 遍历。"""

from __future__ import annotations
from collections import deque


def dfs_order(adj: list[list[int]], start: int) -> list[int]:
    n = len(adj)
    seen = [False] * n
    out: list[int] = []

    def dfs(u: int) -> None:
        seen[u] = True
        out.append(u)
        for v in adj[u]:
            if not seen[v]:
                dfs(v)

    dfs(start)
    return out


def bfs_order(adj: list[list[int]], start: int) -> list[int]:
    n = len(adj)
    seen = [False] * n
    q: deque[int] = deque([start])
    seen[start] = True
    out: list[int] = []
    while q:
        u = q.popleft()
        out.append(u)
        for v in adj[u]:
            if not seen[v]:
                seen[v] = True
                q.append(v)
    return out


if __name__ == "__main__":
    adj = [[] for _ in range(4)]
    for u, v in [(0, 1), (0, 2), (1, 3)]:
        adj[u].append(v)
        adj[v].append(u)
    assert dfs_order(adj, 0) == [0, 1, 3, 2]
    assert bfs_order(adj, 0) == [0, 1, 2, 3]
    assert dfs_order([[]], 0) == [0]
    print("graph_traversal OK")
