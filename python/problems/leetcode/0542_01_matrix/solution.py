"""LeetCode 542: 01 Matrix."""

from __future__ import annotations

from collections import deque


class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        m, n = len(mat), len(mat[0])
        dist = [[10**9] * n for _ in range(m)]
        q: deque[tuple[int, int]] = deque()
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                    q.append((i, j))
        while q:
            i, j = q.popleft()
            for di, dj in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and dist[ni][nj] > dist[i][j] + 1:
                    dist[ni][nj] = dist[i][j] + 1
                    q.append((ni, nj))
        return dist


if __name__ == "__main__":
    assert Solution().updateMatrix([[0, 0, 0], [0, 1, 0], [0, 0, 0]]) == [
        [0, 0, 0],
        [0, 1, 0],
        [0, 0, 0],
    ]
    assert Solution().updateMatrix([[0, 0, 0], [0, 0, 0], [0, 1, 0]]) == [
        [0, 0, 0],
        [0, 0, 0],
        [0, 1, 0],
    ]
    print("0542 OK")
