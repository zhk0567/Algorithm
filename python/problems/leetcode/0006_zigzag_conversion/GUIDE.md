# LeetCode 6 — Zigzag Conversion（Z 字形变换）

## 题面

- **来源**：LeetCode 6
- **链接**：<https://leetcode.cn/problems/zigzag-conversion/>
- **简述**：按 Z 字形把字符串排成 `numRows` 行，再按行拼接读出。

## 思路

直接模拟：维护方向（到顶/底翻转），按行追加。

## 复杂度

时间 O(n)，空间 O(n)。
