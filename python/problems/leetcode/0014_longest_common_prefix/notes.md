# LeetCode 14 — Longest Common Prefix（最长公共前缀）

## 题面

- **来源**：LeetCode 14
- **链接**：<https://leetcode.cn/problems/longest-common-prefix/>
- **简述**：返回字符串数组的最长公共前缀。

## 思路

**纵向扫描**：以第一串为基准，逐列比较每个字符，遇到不同或越界即返回。

## 复杂度

时间 O(S)（S 为所有字符总数），空间 O(1)。
