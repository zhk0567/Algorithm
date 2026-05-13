"""LeetCode 37: Sudoku Solver."""

from __future__ import annotations


class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        empties: list[tuple[int, int]] = []
        for i in range(9):
            for j in range(9):
                ch = board[i][j]
                if ch == ".":
                    empties.append((i, j))
                else:
                    d = int(ch) - 1
                    mask = 1 << d
                    rows[i] |= mask
                    cols[j] |= mask
                    boxes[(i // 3) * 3 + j // 3] |= mask

        def bt(k: int) -> bool:
            if k == len(empties):
                return True
            i, j = empties[k]
            b = (i // 3) * 3 + j // 3
            used = rows[i] | cols[j] | boxes[b]
            for d in range(9):
                mask = 1 << d
                if used & mask:
                    continue
                rows[i] |= mask
                cols[j] |= mask
                boxes[b] |= mask
                board[i][j] = str(d + 1)
                if bt(k + 1):
                    return True
                rows[i] ^= mask
                cols[j] ^= mask
                boxes[b] ^= mask
                board[i][j] = "."
            return False

        bt(0)


if __name__ == "__main__":
    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    Solution().solveSudoku(board)
    for row in board:
        nums = sorted(row)
        assert nums == ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
    for j in range(9):
        col = sorted(board[i][j] for i in range(9))
        assert col == ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
    print("0037 OK")
