# LeetCode 122 — Best Time to Buy and Sell Stock II（买卖股票的最佳时机 II）

## 题面

- **来源**：LeetCode 122
- **链接**：<https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/>
- **简述**：可多次买卖（每天最多持有一股，必须卖出后才能再买），求最大利润。

## 思路

**贪心**：所有上涨段累加，等价于在每个相邻上涨日各买卖一次。

## 复杂度

时间 O(n)，空间 O(1)。
