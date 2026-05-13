"""LeetCode 22: Generate Parentheses."""

from __future__ import annotations


class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res: list[str] = []

        def bt(s: str, open_: int, close: int) -> None:
            if len(s) == 2 * n:
                res.append(s)
                return
            if open_ < n:
                bt(s + "(", open_ + 1, close)
            if close < open_:
                bt(s + ")", open_, close + 1)

        bt("", 0, 0)
        return res


if __name__ == "__main__":
    out3 = set(Solution().generateParenthesis(3))
    assert out3 == {"((()))", "(()())", "(())()", "()(())", "()()()"}
    assert Solution().generateParenthesis(1) == ["()"]
    print("0022 OK")
