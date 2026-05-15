"""扩展欧几里得：ax+by=gcd(a,b)；可解线性同余与模逆。"""

from __future__ import annotations


def extgcd(a: int, b: int) -> tuple[int, int, int]:
    """返回 (g, x, y) 满足 ax + by = g = gcd(a, b)。"""
    if b == 0:
        return abs(a), 1 if a >= 0 else -1, 0
    g, x1, y1 = extgcd(b, a % b)
    return g, y1, x1 - (a // b) * y1


def mod_inverse(a: int, mod: int) -> int | None:
    """a 与 mod 互素时返回 x 使 ax ≡ 1 (mod mod)；否则 None。"""
    g, x, _ = extgcd(a % mod, mod)
    if g != 1:
        return None
    return x % mod


def solve_linear_congruence(a: int, b: int, m: int) -> tuple[int, int] | None:
    """求最小非负 x 使 ax ≡ b (mod m)；无解返回 None，否则 (x0, period)。"""
    g, x0, _ = extgcd(a % m, m)
    if b % g != 0:
        return None
    mod_m = m // g
    x0 = (x0 * (b // g)) % mod_m
    return x0, mod_m


if __name__ == "__main__":
    g, x, y = extgcd(35, 15)
    assert g == 5 and 35 * x + 15 * y == 5

    assert mod_inverse(3, 11) == 4
    assert mod_inverse(4, 6) is None

    sol = solve_linear_congruence(3, 2, 7)
    assert sol is not None
    x0, period = sol
    assert (3 * x0 - 2) % 7 == 0
    print("extended_gcd OK")
