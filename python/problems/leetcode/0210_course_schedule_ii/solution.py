"""LeetCode 210: Course Schedule II."""

from __future__ import annotations

from collections import defaultdict, deque


class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        g: dict[int, list[int]] = defaultdict(list)
        indeg = [0] * numCourses
        for a, b in prerequisites:
            g[b].append(a)
            indeg[a] += 1
        q: deque[int] = deque(i for i, d in enumerate(indeg) if d == 0)
        order: list[int] = []
        while q:
            x = q.popleft()
            order.append(x)
            for y in g[x]:
                indeg[y] -= 1
                if indeg[y] == 0:
                    q.append(y)
        return order if len(order) == numCourses else []


if __name__ == "__main__":
    assert Solution().findOrder(2, [[1, 0]]) == [0, 1]
    assert Solution().findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]) == [0, 1, 2, 3]
    assert Solution().findOrder(2, [[1, 0], [0, 1]]) == []
    print("0210 OK")
