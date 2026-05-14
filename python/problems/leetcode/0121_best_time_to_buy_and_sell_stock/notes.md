# LeetCode 121 — Best Time to Buy and Sell Stock（买卖股票的最佳时机）

## 题面

- **来源**：LeetCode 121
- **链接**：<https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/>
- **简述**：价格数组，最多一笔买卖（先买后卖），求最大利润。

## 思路

遍历维护历史最低价 `min_price`，当日卖出利润 `price - min_price`，取最大。

## 复杂度

O(n) 时间，O(1) 空间。

## 相关题目

- LeetCode 122、123、188、309 等股票系列
