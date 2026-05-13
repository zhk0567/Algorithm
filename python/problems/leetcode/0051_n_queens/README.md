# LeetCode 51 — N-Queens（N 皇后）

## 题面

- **来源**：LeetCode 51
- **链接**：<https://leetcode.cn/problems/n-queens/>
- **简述**：返回所有 `n x n` 棋盘上放置 `n` 个皇后且互不攻击的方案。

## 思路

回溯按行放：用三个集合分别记录已占列、主对角线（`r-c`）与副对角线（`r+c`）。

## 复杂度

时间 O(n!)，空间 O(n)。
