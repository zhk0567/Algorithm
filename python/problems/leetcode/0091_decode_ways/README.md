# LeetCode 91 — Decode Ways（解码方法）

## 题面

- **来源**：LeetCode 91
- **链接**：<https://leetcode.cn/problems/decode-ways/>
- **简述**：字符 `'A'..'Z'` 对应 `1..26`，给定数字串问解码方式数；`'0'` 不能独立成字母。

## 思路

线性 DP：`dp[i] = dp[i-1] (若 s[i-1] != '0') + dp[i-2] (若 s[i-2..i-1] 在 10..26)`。

## 复杂度

时间 O(n)，空间 O(1)（滚动）。
