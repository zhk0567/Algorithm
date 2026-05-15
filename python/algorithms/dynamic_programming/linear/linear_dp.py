"""线性 DP：LIS(nlogn)、LCS、编辑距离、打家劫舍。"""

from __future__ import annotations
import bisect


def length_of_lis(nums: list[int]) -> int:
    tails: list[int] = []
    for x in nums:
        i = bisect.bisect_left(tails, x)
        if i == len(tails):
            tails.append(x)
        else:
            tails[i] = x
    return len(tails)


def longest_common_subsequence(a: str, b: str) -> int:
    na, nb = len(a), len(b)
    dp = [[0] * (nb + 1) for _ in range(na + 1)]
    for i in range(1, na + 1):
        for j in range(1, nb + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[na][nb]


def edit_distance(a: str, b: str) -> int:
    na, nb = len(a), len(b)
    dp = [[0] * (nb + 1) for _ in range(na + 1)]
    for i in range(na + 1):
        dp[i][0] = i
    for j in range(nb + 1):
        dp[0][j] = j
    for i in range(1, na + 1):
        for j in range(1, nb + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    return dp[na][nb]


def house_robber(nums: list[int]) -> int:
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]
    prev2, prev1 = 0, 0
    for x in nums:
        prev2, prev1 = prev1, max(prev1, prev2 + x)
    return prev1


if __name__ == "__main__":
    assert length_of_lis([10, 9, 2, 5, 3, 7, 101, 18]) == 4
    assert longest_common_subsequence("abcde", "ace") == 3
    assert edit_distance("horse", "ros") == 3
    assert house_robber([2, 7, 9, 3, 1]) == 12
    assert length_of_lis([]) == 0
    assert longest_common_subsequence("", "") == 0
    assert house_robber([]) == 0 and house_robber([5]) == 5
    print("linear_dp OK")
