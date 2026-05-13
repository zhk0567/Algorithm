"""LeetCode 17: Letter Combinations of a Phone Number."""

from __future__ import annotations

_MAP: dict[str, str] = {
    "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
    "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz",
}


class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        if not digits:
            return []
        res: list[str] = []
        buf: list[str] = []

        def bt(i: int) -> None:
            if i == len(digits):
                res.append("".join(buf))
                return
            for ch in _MAP[digits[i]]:
                buf.append(ch)
                bt(i + 1)
                buf.pop()

        bt(0)
        return res


if __name__ == "__main__":
    out = Solution().letterCombinations("23")
    assert set(out) == {
        "ad", "ae", "af", "bd", "be",
        "bf", "cd", "ce", "cf",
    }
    assert Solution().letterCombinations("") == []
    assert Solution().letterCombinations("2") == ["a", "b", "c"]
    print("0017 OK")
