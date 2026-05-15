"""LeetCode 785: Is Graph Bipartite?"""

from __future__ import annotations

from collections import deque


class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        color = [-1] * n

        for start in range(n):
            if color[start] != -1:
                continue
            color[start] = 0
            q: deque[int] = deque([start])
            while q:
                u = q.popleft()
                for v in graph[u]:
                    if color[v] == -1:
                        color[v] = color[u] ^ 1
                        q.append(v)
                    elif color[v] == color[u]:
                        return False
        return True


if __name__ == "__main__":
    assert Solution().isBipartite([[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]) is False
    assert Solution().isBipartite([[1, 3], [0, 2], [1, 3], [0, 2]]) is True
    assert Solution().isBipartite([[]]) is True
    print("0785 OK")
