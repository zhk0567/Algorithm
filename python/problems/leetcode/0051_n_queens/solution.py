"""LeetCode 51: N-Queens."""

from __future__ import annotations


class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        res: list[list[str]] = []
        cols: set[int] = set()
        diag1: set[int] = set()
        diag2: set[int] = set()
        cur: list[int] = []

        def bt(r: int) -> None:
            if r == n:
                board = []
                for c in cur:
                    row = ["."] * n
                    row[c] = "Q"
                    board.append("".join(row))
                res.append(board)
                return
            for c in range(n):
                if c in cols or (r - c) in diag1 or (r + c) in diag2:
                    continue
                cols.add(c)
                diag1.add(r - c)
                diag2.add(r + c)
                cur.append(c)
                bt(r + 1)
                cur.pop()
                cols.discard(c)
                diag1.discard(r - c)
                diag2.discard(r + c)

        bt(0)
        return res


if __name__ == "__main__":
    assert len(Solution().solveNQueens(4)) == 2
    assert Solution().solveNQueens(1) == [["Q"]]
    assert len(Solution().solveNQueens(8)) == 92
    print("0051 OK")
