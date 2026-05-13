# LeetCode 28 — Find the Index of the First Occurrence in a String（实现 strStr）

## 题面

- **来源**：LeetCode 28
- **链接**：<https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/>
- **简述**：返回 `needle` 在 `haystack` 中首次出现的下标；不在则返回 −1。

## 思路

**KMP**：先求 `needle` 的 next 数组，再线性扫描原串。

## 复杂度

时间 O(n+m)，空间 O(m)。
