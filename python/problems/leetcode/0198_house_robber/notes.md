# LeetCode 198 — House Robber（打家劫舍）

## 题面

- **来源**：LeetCode 198
- **链接**：<https://leetcode.cn/problems/house-robber/>
- **简述**：相邻不能同偷，求最大金额。

## 思路

线性 DP：`dp[i] = max(dp[i-1], dp[i-2] + nums[i])`，滚动两个变量即可 O(1) 空间。

## 复杂度

时间 O(n)，空间 O(1)。
