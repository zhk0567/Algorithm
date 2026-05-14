# LeetCode 13 — Roman to Integer（罗马数字转整数）

## 题面

- **来源**：LeetCode 13
- **链接**：<https://leetcode.cn/problems/roman-to-integer/>
- **简述**：将罗马数字字符串转为整数（1 ≤ value ≤ 3999）。

## 思路

从左到右扫描：若当前值小于右邻值则减，否则加。

## 复杂度

时间 O(n)，空间 O(1)。
