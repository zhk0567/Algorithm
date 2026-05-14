# LeetCode 85 — Maximal Rectangle（最大矩形）

## 题面

- **来源**：LeetCode 85
- **链接**：<https://leetcode.cn/problems/maximal-rectangle/>
- **简述**：仅含 `'0'`/`'1'` 的矩阵中只含 `'1'` 的最大矩形面积。

## 思路

按行视作直方图：每行的高度为该列连续 `'1'` 数，对每行用 LC84 单调栈求最大矩形。

## 复杂度

时间 O(mn)，空间 O(n)。
