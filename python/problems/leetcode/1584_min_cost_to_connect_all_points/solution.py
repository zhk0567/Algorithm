"""LeetCode 1584: Min Cost to Connect All Points."""

from __future__ import annotations


class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        n = len(points)
        if n <= 1:
            return 0
        dist = [10**18] * n
        dist[0] = 0
        visited = [False] * n
        total = 0

        def manhattan(i: int, j: int) -> int:
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])

        for _ in range(n):
            u = -1
            best = 10**18
            for i in range(n):
                if not visited[i] and dist[i] < best:
                    best = dist[i]
                    u = i
            visited[u] = True
            total += best
            for v in range(n):
                if not visited[v]:
                    w = manhattan(u, v)
                    if w < dist[v]:
                        dist[v] = w
        return total


if __name__ == "__main__":
    assert Solution().minCostConnectPoints([[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]) == 20
    assert Solution().minCostConnectPoints([[3, 12], [-2, 5], [-4, 1]]) == 18
    assert Solution().minCostConnectPoints([[0, 0]]) == 0
    print("1584 OK")
