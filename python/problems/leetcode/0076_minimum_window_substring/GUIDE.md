# LeetCode 76 — Minimum Window Substring（最小覆盖子串）

## 题面

- **来源**：LeetCode 76
- **链接**：<https://leetcode.cn/problems/minimum-window-substring/>
- **简述**：在 `s` 中找包含 `t` 所有字符（含频次）的最短子串。

## 思路

**滑动窗口 + 计数差**：右端扩张，统计 `have == need` 的字符种类数；命中后左端收缩并更新答案。

## 复杂度

时间 O(|s|+|t|)，空间 O(|s|+|t|)。
