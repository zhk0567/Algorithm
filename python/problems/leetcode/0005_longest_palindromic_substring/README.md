# LeetCode 5 — Longest Palindromic Substring（最长回文子串）

## 题面

- **来源**：LeetCode 5
- **链接**：<https://leetcode.cn/problems/longest-palindromic-substring/>
- **简述**：求字符串中最长回文连续子串。

## 思路

**中心扩展**：枚举每个中心（奇/偶长度），向两侧扩展，O(n²)。

## 复杂度

时间 O(n²)，空间 O(1)。

## 相关题目

- LeetCode 647（回文子串个数）、Manacher（O(n)）扩展
