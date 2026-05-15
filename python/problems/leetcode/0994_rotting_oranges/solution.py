"""LeetCode 994: Rotting Oranges."""

from __future__ import annotations

from collections import deque


class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q: deque[tuple[int, int, int]] = deque()
        fresh = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j, 0))
                elif grid[i][j] == 1:
                    fresh += 1
        if fresh == 0:
            return 0
        minutes = 0
        while q:
            i, j, t = q.popleft()
            minutes = max(minutes, t)
            for di, dj in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] == 1:
                    grid[ni][nj] = 2
                    fresh -= 1
                    q.append((ni, nj, t + 1))
        return minutes if fresh == 0 else -1


if __name__ == "__main__":
    g = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
    assert Solution().orangesRotting(g) == 4
    g2 = [[2, 1, 1], [0, 1, 1], [1, 0, 1]]
    assert Solution().orangesRotting(g2) == -1
    assert Solution().orangesRotting([[0]]) == 0
    print("0994 OK")
