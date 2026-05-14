# LeetCode 279 — Perfect Squares（完全平方数）

## 题面

- **来源**：LeetCode 279
- **链接**：<https://leetcode.cn/problems/perfect-squares/>
- **简述**：返回和为 `n` 的最少完全平方数个数。

## 思路

完全背包 DP：`dp[i] = 1 + min(dp[i - j*j])`，其中 `j*j <= i`。

## 复杂度

时间 O(n√n)，空间 O(n)。
