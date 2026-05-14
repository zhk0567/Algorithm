# LeetCode 64 — Minimum Path Sum（最小路径和）

## 题面

- **来源**：LeetCode 64
- **链接**：<https://leetcode.cn/problems/minimum-path-sum/>
- **简述**：从左上到右下，每步只能向右或向下，求路径数字总和最小值。

## 思路

原地 DP：`grid[i][j] += min(grid[i-1][j], grid[i][j-1])`。

## 复杂度

时间 O(mn)，空间 O(1)。
