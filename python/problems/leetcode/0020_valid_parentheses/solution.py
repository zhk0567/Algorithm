"""LeetCode 20: Valid Parentheses."""

from __future__ import annotations


class Solution:
    def isValid(self, s: str) -> bool:
        st: list[str] = []
        pair = {")": "(", "]": "[", "}": "{"}
        for ch in s:
            if ch in "([{":
                st.append(ch)
            else:
                if not st or st[-1] != pair[ch]:
                    return False
                st.pop()
        return len(st) == 0


if __name__ == "__main__":
    assert Solution().isValid("()[]{}")
    assert not Solution().isValid("(]")
    print("0020 OK")
