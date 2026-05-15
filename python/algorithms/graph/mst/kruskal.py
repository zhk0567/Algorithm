"""Kruskal 最小生成树。"""

from __future__ import annotations


class UF:
    def __init__(self, n: int) -> None:
        self.p = list(range(n))
        self.r = [0] * n

    def find(self, x: int) -> int:
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x

    def unite(self, a: int, b: int) -> bool:
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if self.r[ra] < self.r[rb]:
            ra, rb = rb, ra
        self.p[rb] = ra
        if self.r[ra] == self.r[rb]:
            self.r[ra] += 1
        return True


def kruskal(n: int, edges: list[tuple[int, int, int]]) -> int:
    """edges: (u,v,w)，无向；返回 MST 边权和。要求图连通。"""
    if n <= 1:
        return 0
    edges = sorted(edges, key=lambda t: t[2])
    uf = UF(n)
    total = 0
    cnt = 0
    for u, v, w in edges:
        if uf.unite(u, v):
            total += w
            cnt += 1
            if cnt == n - 1:
                break
    if cnt < n - 1:
        raise ValueError("graph is not connected")
    return total


if __name__ == "__main__":
    # 三角形 0-1:4, 1-2:3, 0-2:2 -> MST 2+3=5
    e = [(0, 1, 4), (1, 2, 3), (0, 2, 2)]
    assert kruskal(3, e) == 5
    assert kruskal(1, []) == 0
    try:
        kruskal(2, [])
        raise AssertionError("expected ValueError")
    except ValueError:
        pass
    print("mst OK")
