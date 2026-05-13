"""LeetCode 13: Roman to Integer."""

from __future__ import annotations

_MAP: dict[str, int] = {
    "I": 1, "V": 5, "X": 10, "L": 50,
    "C": 100, "D": 500, "M": 1000,
}


class Solution:
    def romanToInt(self, s: str) -> int:
        total = 0
        n = len(s)
        for i, ch in enumerate(s):
            v = _MAP[ch]
            if i + 1 < n and v < _MAP[s[i + 1]]:
                total -= v
            else:
                total += v
        return total


if __name__ == "__main__":
    assert Solution().romanToInt("III") == 3
    assert Solution().romanToInt("LVIII") == 58
    assert Solution().romanToInt("MCMXCIV") == 1994
    print("0013 OK")
