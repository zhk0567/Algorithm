"""区间 DP：矩阵链乘最小乘法次数。"""

from __future__ import annotations


def matrix_chain_order(p: list[int]) -> int:
    """p 长度 n+1，矩阵 i 维度 p[i] x p[i+1]；返回最少标量乘法次数。"""
    n = len(p) - 1
    if n <= 0:
        return 0
    dp = [[0] * n for _ in range(n)]
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = 10**18
            for k in range(i, j):
                cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                dp[i][j] = min(dp[i][j], cost)
    return dp[0][n - 1]


if __name__ == "__main__":
    # 3 个矩阵 A1:10x20, A2:20x30, A3:30x40 -> p=[10,20,30,40]
    assert matrix_chain_order([10, 20, 30, 40]) == 10 * 20 * 30 + 10 * 30 * 40
    assert matrix_chain_order([10]) == 0
    print("interval_dp OK")
