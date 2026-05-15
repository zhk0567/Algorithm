"""Z 函数（扩展 KMP）：线性求每个后缀与前缀的最长公共前缀长度。"""

from __future__ import annotations


def z_function(s: str) -> list[int]:
    n = len(s)
    if n == 0:
        return []
    z = [0] * n
    l = r = 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
    return z


def z_search(text: str, pat: str) -> list[int]:
    """返回 pat 在 text 中所有起始下标。"""
    if not pat:
        return list(range(len(text) + 1))
    if len(pat) > len(text):
        return []
    combined = pat + "\x00" + text
    z = z_function(combined)
    m = len(pat)
    return [i - m - 1 for i in range(m + 1, len(combined)) if z[i] == m]


if __name__ == "__main__":
    assert z_function("aaabaab") == [0, 2, 1, 0, 2, 1, 0]
    assert z_search("ababa", "aba") == [0, 2]
    assert z_function("") == []
    assert z_search("ab", "xyz") == []
    assert z_search("ab", "") == [0, 1, 2]
    print("z_algorithm OK")
