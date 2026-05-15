"""快速幂：二进制幂；模运算版为刷题常用入口。"""

from __future__ import annotations


def fast_pow(a: int, e: int) -> int:
    """a^e（非模；指数很大时注意溢出）。"""
    r = 1
    base = a
    while e:
        if e & 1:
            r *= base
        base *= base
        e >>= 1
    return r


def mod_pow(a: int, e: int, mod: int) -> int:
    """a^e mod mod。"""
    if mod == 1:
        return 0
    r = 1 % mod
    a %= mod
    while e:
        if e & 1:
            r = (r * a) % mod
        a = (a * a) % mod
        e >>= 1
    return r


if __name__ == "__main__":
    assert fast_pow(2, 10) == 1024
    assert fast_pow(3, 0) == 1
    assert mod_pow(7, 10, 13) == 4
    assert mod_pow(2, 100, 1_000_000_007) == 976371285
    assert mod_pow(7, 0, 1) == 0
    print("fast_power OK")
