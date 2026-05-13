"""LeetCode 121: Best Time to Buy and Sell Stock."""

from __future__ import annotations


class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        lo = 10**9
        best = 0
        for p in prices:
            lo = min(lo, p)
            best = max(best, p - lo)
        return best


if __name__ == "__main__":
    assert Solution().maxProfit([7, 1, 5, 3, 6, 4]) == 5
    assert Solution().maxProfit([7, 6, 4, 3, 1]) == 0
    print("0121 OK")
