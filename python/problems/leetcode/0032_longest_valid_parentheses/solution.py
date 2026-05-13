"""LeetCode 32: Longest Valid Parentheses."""

from __future__ import annotations


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack: list[int] = [-1]
        best = 0
        for i, ch in enumerate(s):
            if ch == "(":
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    best = max(best, i - stack[-1])
        return best


if __name__ == "__main__":
    assert Solution().longestValidParentheses("(()") == 2
    assert Solution().longestValidParentheses(")()())") == 4
    assert Solution().longestValidParentheses("") == 0
    print("0032 OK")
