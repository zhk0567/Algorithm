"""LeetCode 847: Shortest Path Visiting All Nodes."""

from __future__ import annotations

from collections import deque


class Solution:
    def shortestPathLength(self, graph: list[list[int]]) -> int:
        n = len(graph)
        if n == 1:
            return 0
        target = (1 << n) - 1
        q: deque[tuple[int, int, int]] = deque()
        seen: set[tuple[int, int]] = set()
        for i in range(n):
            mask = 1 << i
            q.append((i, mask, 0))
            seen.add((i, mask))
        while q:
            u, mask, dist = q.popleft()
            if mask == target:
                return dist
            for v in graph[u]:
                nmask = mask | (1 << v)
                state = (v, nmask)
                if state not in seen:
                    seen.add(state)
                    q.append((v, nmask, dist + 1))
        return -1


if __name__ == "__main__":
    assert Solution().shortestPathLength([[1, 2, 3], [0], [0], [0]]) == 4
    assert Solution().shortestPathLength([[1], [0]]) == 1
    assert Solution().shortestPathLength([[]]) == 0
    print("0847 OK")
