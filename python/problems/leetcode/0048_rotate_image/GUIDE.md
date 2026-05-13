# LeetCode 48 — Rotate Image（旋转图像）

## 题面

- **来源**：LeetCode 48
- **链接**：<https://leetcode.cn/problems/rotate-image/>
- **简述**：将 `n x n` 矩阵顺时针旋转 90°，原地操作。

## 思路

先沿主对角线转置，再每行左右翻转。

## 复杂度

时间 O(n²)，空间 O(1)。
