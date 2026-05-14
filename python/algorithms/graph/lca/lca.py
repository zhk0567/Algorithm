"""树上倍增 LCA（最近公共祖先）。"""

from __future__ import annotations

from typing import List, Tuple


class BinaryLiftingLCA:
    def __init__(self, n: int, edges: List[Tuple[int, int]], root: int = 0) -> None:
        self._n = n
        self._log = max(1, (n + 1).bit_length())
        self._g: List[List[int]] = [[] for _ in range(n)]
        for u, v in edges:
            self._g[u].append(v)
            self._g[v].append(u)
        self._depth = [0] * n
        self._up = [[-1] * n for _ in range(self._log)]

        def dfs(u: int, p: int) -> None:
            self._up[0][u] = p
            for k in range(1, self._log):
                mid = self._up[k - 1][u]
                self._up[k][u] = self._up[k - 1][mid] if mid != -1 else -1
            for v in self._g[u]:
                if v != p:
                    self._depth[v] = self._depth[u] + 1
                    dfs(v, u)

        dfs(root, -1)

    def lca(self, u: int, v: int) -> int:
        if self._depth[u] < self._depth[v]:
            u, v = v, u
        d = self._depth[u] - self._depth[v]
        for k in range(self._log):
            if d >> k & 1:
                u = self._up[k][u]
        if u == v:
            return u
        for k in range(self._log - 1, -1, -1):
            if self._up[k][u] != self._up[k][v]:
                u = self._up[k][u]
                v = self._up[k][v]
        return self._up[0][u]


if __name__ == "__main__":
    #       0
    #     /   \
    #    1     2
    #         / \
    #        3   4
    n = 5
    ed = [(0, 1), (0, 2), (2, 3), (2, 4)]
    t = BinaryLiftingLCA(n, ed, 0)
    assert t.lca(3, 4) == 2
    assert t.lca(1, 3) == 0
    assert t.lca(1, 2) == 0
    assert t.lca(0, 4) == 0
    print("lca OK")
