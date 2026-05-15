"""LeetCode 743: Network Delay Time."""

from __future__ import annotations

import heapq


class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        adj: list[list[tuple[int, int]]] = [[] for _ in range(n)]
        for u, v, w in times:
            adj[u - 1].append((v - 1, w))
        inf = 10**9
        dist = [inf] * n
        dist[k - 1] = 0
        pq: list[tuple[int, int]] = [(0, k - 1)]
        while pq:
            d, u = heapq.heappop(pq)
            if d != dist[u]:
                continue
            for v, w in adj[u]:
                nd = d + w
                if nd < dist[v]:
                    dist[v] = nd
                    heapq.heappush(pq, (nd, v))
        mx = max(dist)
        return mx if mx < inf else -1


if __name__ == "__main__":
    assert Solution().networkDelayTime([[2, 1, 1], [1, 3, 1], [2, 3, 1]], 3, 2) == 1
    assert Solution().networkDelayTime([[2, 1, 1], [1, 3, 1], [2, 3, 1]], 4, 2) == -1
    assert Solution().networkDelayTime([[1, 2, 1]], 2, 1) == 1
    assert Solution().networkDelayTime([[1, 2, 1]], 2, 2) == -1
    print("0743 OK")
