"""LeetCode 207: Course Schedule."""

from __future__ import annotations

from collections import defaultdict, deque


class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        g: dict[int, list[int]] = defaultdict(list)
        indeg = [0] * numCourses
        for a, b in prerequisites:
            g[b].append(a)
            indeg[a] += 1
        q: deque[int] = deque(i for i, d in enumerate(indeg) if d == 0)
        done = 0
        while q:
            x = q.popleft()
            done += 1
            for y in g[x]:
                indeg[y] -= 1
                if indeg[y] == 0:
                    q.append(y)
        return done == numCourses


if __name__ == "__main__":
    assert Solution().canFinish(2, [[1, 0]])
    assert not Solution().canFinish(2, [[1, 0], [0, 1]])
    assert Solution().canFinish(4, [[1, 0], [2, 0], [3, 1], [3, 2]])
    print("0207 OK")
