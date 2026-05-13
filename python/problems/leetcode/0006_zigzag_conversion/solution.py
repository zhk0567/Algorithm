"""LeetCode 6: Zigzag Conversion."""

from __future__ import annotations


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        rows: list[list[str]] = [[] for _ in range(numRows)]
        i, step = 0, 1
        for ch in s:
            rows[i].append(ch)
            if i == 0:
                step = 1
            elif i == numRows - 1:
                step = -1
            i += step
        return "".join("".join(r) for r in rows)


if __name__ == "__main__":
    assert Solution().convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR"
    assert Solution().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI"
    assert Solution().convert("A", 1) == "A"
    print("0006 OK")
