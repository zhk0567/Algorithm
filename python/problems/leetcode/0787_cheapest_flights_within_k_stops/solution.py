"""LeetCode 787: Cheapest Flights Within K Stops."""

from __future__ import annotations


class Solution:
    def findCheapestPrice(
        self,
        n: int,
        flights: list[list[int]],
        src: int,
        dst: int,
        k: int,
    ) -> int:
        inf = 10**9
        dist = [inf] * n
        dist[src] = 0
        for _ in range(k + 1):
            nxt = dist[:]
            for u, v, w in flights:
                if dist[u] != inf:
                    nxt[v] = min(nxt[v], dist[u] + w)
            dist = nxt
        return dist[dst] if dist[dst] != inf else -1


if __name__ == "__main__":
    assert Solution().findCheapestPrice(3, [[0, 1, 100], [1, 2, 100], [0, 2, 500]], 0, 2, 1) == 200
    assert Solution().findCheapestPrice(3, [[0, 1, 100], [1, 2, 100], [0, 2, 500]], 0, 2, 0) == 500
    assert Solution().findCheapestPrice(3, [[0, 1, 100], [1, 2, 100]], 0, 2, 1) == 200
    print("0787 OK")
