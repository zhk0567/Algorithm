"""Manacher：O(n) 求最长回文子串。"""

from __future__ import annotations


def longest_palindrome(s: str) -> str:
    if not s:
        return ""
    t = "#" + "#".join(s) + "#"
    n = len(t)
    p = [0] * n
    c = r = 0
    best_i = 0
    for i in range(1, n):
        mirror = 2 * c - i
        if i < r:
            p[i] = min(r - i, p[mirror])
        while i - p[i] - 1 >= 0 and i + p[i] + 1 < n and t[i - p[i] - 1] == t[i + p[i] + 1]:
            p[i] += 1
        if i + p[i] > r:
            c, r = i, i + p[i]
        if p[i] > p[best_i]:
            best_i = i
    start = (best_i - p[best_i]) // 2
    return s[start : start + p[best_i]]


if __name__ == "__main__":
    assert longest_palindrome("babad") in ("bab", "aba")
    assert longest_palindrome("cbbd") == "bb"
    assert longest_palindrome("a") == "a"
    assert longest_palindrome("") == ""
    print("manacher OK")
