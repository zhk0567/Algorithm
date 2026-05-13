"""矩阵快速幂：斐波那契。"""

from __future__ import annotations


def mat_mul(a: list[list[int]], b: list[list[int]], mod: int) -> list[list[int]]:
    n = len(a)
    m = len(b[0])
    k = len(b)
    c = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            s = 0
            for t in range(k):
                s = (s + a[i][t] * b[t][j]) % mod
            c[i][j] = s
    return c


def mat_pow(mat: list[list[int]], e: int, mod: int) -> list[list[int]]:
    n = len(mat)
    res = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    base = [row[:] for row in mat]
    while e:
        if e & 1:
            res = mat_mul(res, base, mod)
        base = mat_mul(base, base, mod)
        e >>= 1
    return res


def fib(n: int, mod: int = 10**9 + 7) -> int:
    if n <= 1:
        return n
    f = [[1, 1], [1, 0]]
    p = mat_pow(f, n - 1, mod)
    return p[0][0]


if __name__ == "__main__":
    mod = 10**9 + 7
    assert fib(10, mod) == 55
    assert fib(100, mod) == 687995182
    print("matrix OK")
