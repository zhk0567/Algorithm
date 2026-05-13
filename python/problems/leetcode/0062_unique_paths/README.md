# LeetCode 62 — Unique Paths（不同路径）

## 题面

- **来源**：LeetCode 62
- **链接**：<https://leetcode.cn/problems/unique-paths/>
- **简述**：`m x n` 网格只能向右或向下，求左上到右下的不同路径数。

## 思路

组合数 `C(m+n-2, m-1)` 或 DP。这里给出滚动 DP 一行。

## 复杂度

时间 O(mn)，空间 O(n)。
