"""数位 DP：统计 [0, n] 中数位和 % K == 0 的整数个数（修正前导零）。"""

from __future__ import annotations
from functools import lru_cache


def count_digit_sum_mod0(n: int, k: int) -> int:
    if k <= 0:
        raise ValueError("k must be positive")
    if n < 0:
        return 0
    s = str(n)

    @lru_cache(maxsize=None)
    def dfs(i: int, tight: bool, mod: int, z: bool) -> int:
        """z=True 表示仍处于前导零阶段（数值尚未开始）。"""
        if i == len(s):
            return 1 if mod == 0 else 0
        limit = int(s[i]) if tight else 9
        total = 0
        for d in range(0, limit + 1):
            ntight = tight and (d == limit)
            nz = z and (d == 0)
            nmod = mod if nz else (mod + d) % k
            total += dfs(i + 1, ntight, nmod, nz)
        return total

    return dfs(0, True, 0, True)


if __name__ == "__main__":
    k = 3

    def brute(nn: int) -> int:
        c = 0
        for x in range(0, nn + 1):
            if sum(int(ch) for ch in str(x)) % k == 0:
                c += 1
        return c

    for nn in range(0, 500):
        assert count_digit_sum_mod0(nn, k) == brute(nn)
    try:
        count_digit_sum_mod0(10, 0)
        raise AssertionError("expected ValueError")
    except ValueError:
        pass
    print("digit_dp OK")
