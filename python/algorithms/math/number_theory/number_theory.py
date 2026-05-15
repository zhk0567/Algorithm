"""数论：gcd、埃氏筛（模幂与扩欧见 fast_power / extended_gcd）。"""

from __future__ import annotations


def gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return abs(a)


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
    sp = sieve(30)
    assert sum(sp) == 10  # primes <=30 count
    assert len(sieve(0)) == 1 and not sieve(0)[0]
    assert sum(sieve(1)) == 0
    print("number_theory OK")
