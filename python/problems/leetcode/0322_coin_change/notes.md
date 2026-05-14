# LeetCode 322 — Coin Change（零钱兑换）

## 题面

- **来源**：LeetCode 322
- **链接**：<https://leetcode.cn/problems/coin-change/>
- **简述**：每种面额无限张，求凑成 `amount` 的最少硬币数；不能凑出返回 −1。

## 思路

完全背包 DP：`dp[x]` 表示凑出 `x` 的最少硬币数，`dp[0]=0`，其余初始化为 `inf`，按面额松弛 `dp[x] = min(dp[x], dp[x-c]+1)`。

## 复杂度

时间 O(amount · |coins|)，空间 O(amount)。
