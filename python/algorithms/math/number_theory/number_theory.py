"""数论：gcd、扩展欧几里得、模幂、埃氏筛。"""

from __future__ import annotations


def gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return abs(a)


def extgcd(a: int, b: int) -> tuple[int, int, int]:
    """返回 (g,x,y) 满足 ax+by=g=gcd(a,b)。"""
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extgcd(b, a % b)
    return g, y1, x1 - (a // b) * y1


def mod_pow(a: int, e: int, mod: int) -> int:
    r = 1 % mod
    a %= mod
    while e:
        if e & 1:
            r = (r * a) % mod
        a = (a * a) % mod
        e >>= 1
    return r


def sieve(n: int) -> list[bool]:
    if n < 2:
        return [False] * (n + 1)
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            step = i
            start = i * i
            for j in range(start, n + 1, step):
                is_prime[j] = False
    return is_prime


if __name__ == "__main__":
    assert gcd(54, 24) == 6
    g, x, y = extgcd(35, 15)
    assert g == 5 == 35 * x + 15 * y
    assert mod_pow(7, 10, 13) == 4
    sp = sieve(30)
    assert sum(sp) == 10  # primes <=30 count
    print("number_theory OK")
