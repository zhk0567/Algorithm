"""KMP 模式匹配。"""

from __future__ import annotations


def build_lps(pat: str) -> list[int]:
    m = len(pat)
    lps = [0] * m
    length = 0
    i = 1
    while i < m:
        if pat[i] == pat[length]:
            length += 1
            lps[i] = length
            i += 1
        elif length:
            length = lps[length - 1]
        else:
            lps[i] = 0
            i += 1
    return lps


def kmp_search(text: str, pat: str) -> list[int]:
    if not pat:
        return list(range(len(text) + 1))
    lps = build_lps(pat)
    res: list[int] = []
    i = j = 0
    while i < len(text):
        if text[i] == pat[j]:
            i += 1
            j += 1
            if j == len(pat):
                res.append(i - j)
                j = lps[j - 1]
        elif j:
            j = lps[j - 1]
        else:
            i += 1
    return res


if __name__ == "__main__":
    assert build_lps("ababaca") == [0, 0, 1, 2, 3, 0, 1]
    assert kmp_search("ababcababa", "aba") == [0, 5, 7]
    print("string OK")
