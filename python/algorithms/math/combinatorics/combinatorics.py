"""组合数 C(n,k) mod MOD（预阶乘）。"""

from __future__ import annotations

MOD = 1_000_000_007


def make_nck(max_n: int):
    fac = [1] * (max_n + 1)
    for i in range(1, max_n + 1):
        fac[i] = fac[i - 1] * i % MOD
    ifac = [1] * (max_n + 1)
    ifac[max_n] = pow(fac[max_n], MOD - 2, MOD)
    for i in range(max_n, 0, -1):
        ifac[i - 1] = ifac[i] * i % MOD

    def nck(n: int, k: int) -> int:
        if k < 0 or k > n:
            return 0
        return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD

    return fac, nck


if __name__ == "__main__":
    _, nck = make_nck(100)
    assert nck(5, 2) == 10
    assert nck(6, 3) == 20
    print("combinatorics OK")
