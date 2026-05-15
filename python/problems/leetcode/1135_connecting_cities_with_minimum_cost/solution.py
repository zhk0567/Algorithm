"""LeetCode 1135: Connecting Cities With Minimum Cost."""

from __future__ import annotations


class Solution:
    def minimumCost(self, n: int, connections: list[list[int]]) -> int:
        parent = list(range(n + 1))
        rank = [0] * (n + 1)

        def find(x: int) -> int:
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def unite(a: int, b: int) -> bool:
            ra, rb = find(a), find(b)
            if ra == rb:
                return False
            if rank[ra] < rank[rb]:
                ra, rb = rb, ra
            parent[rb] = ra
            if rank[ra] == rank[rb]:
                rank[ra] += 1
            return True

        edges = sorted((c, a, b) for a, b, c in connections)
        total = 0
        cnt = 0
        for cost, u, v in edges:
            if unite(u, v):
                total += cost
                cnt += 1
                if cnt == n - 1:
                    return total
        return -1


if __name__ == "__main__":
    assert Solution().minimumCost(3, [[1, 2, 5], [1, 3, 6], [2, 3, 1]]) == 6
    assert Solution().minimumCost(4, [[1, 2, 1], [2, 3, 2], [3, 4, 1], [1, 4, 3]]) == 4
    assert Solution().minimumCost(2, [[1, 2, 5]]) == 5
    print("1135 OK")
