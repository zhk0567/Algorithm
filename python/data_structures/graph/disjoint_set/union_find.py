"""并查集：路径压缩 + 按秩合并（注释含按大小合并思路）。"""

from __future__ import annotations


class UnionFind:
    def __init__(self, n: int) -> None:
        self._parent = list(range(n))
        self._rank = [0] * n
        # 按大小合并可维护 size[i] = 以 i 为根的集合大小，unite 时把小 size 连到大 size

    def find(self, x: int) -> int:
        if self._parent[x] != x:
            self._parent[x] = self.find(self._parent[x])
        return self._parent[x]

    def unite(self, a: int, b: int) -> bool:
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if self._rank[ra] < self._rank[rb]:
            ra, rb = rb, ra
        self._parent[rb] = ra
        if self._rank[ra] == self._rank[rb]:
            self._rank[ra] += 1
        return True


if __name__ == "__main__":
    uf = UnionFind(5)
    assert uf.unite(0, 1) and uf.unite(1, 2)
    assert uf.find(0) == uf.find(2)
    assert not uf.unite(0, 2)
    uf1 = UnionFind(1)
    assert uf1.find(0) == 0 and not uf1.unite(0, 0)
    print("UnionFind OK")
