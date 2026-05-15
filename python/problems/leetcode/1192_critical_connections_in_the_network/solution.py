"""LeetCode 1192: Critical Connections in a Network."""

from __future__ import annotations


class Solution:
    def criticalConnections(self, n: int, connections: list[list[int]]) -> list[list[int]]:
        g: list[list[int]] = [[] for _ in range(n)]
        for a, b in connections:
            g[a].append(b)
            g[b].append(a)
        dfn = [-1] * n
        low = [0] * n
        t = 0
        res: list[list[int]] = []

        def dfs(u: int, p: int) -> None:
            nonlocal t
            dfn[u] = low[u] = t
            t += 1
            for v in g[u]:
                if v == p:
                    continue
                if dfn[v] == -1:
                    dfs(v, u)
                    low[u] = min(low[u], low[v])
                    if low[v] > dfn[u]:
                        res.append([u, v] if u < v else [v, u])
                else:
                    low[u] = min(low[u], dfn[v])

        for i in range(n):
            if dfn[i] == -1:
                dfs(i, -1)
        return res


if __name__ == "__main__":
    got = Solution().criticalConnections(4, [[0, 1], [1, 2], [2, 0], [1, 3]])
    assert got == [[1, 3]]
    got2 = Solution().criticalConnections(2, [[0, 1]])
    assert got2 == [[0, 1]]
    print("1192 OK")
