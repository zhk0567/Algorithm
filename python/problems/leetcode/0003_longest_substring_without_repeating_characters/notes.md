# LeetCode 3 — Longest Substring Without Repeating Characters（无重复字符的最长子串）

## 题面

- **来源**：LeetCode 3
- **链接**：<https://leetcode.cn/problems/longest-substring-without-repeating-characters/>
- **简述**：给定字符串，求不含重复字符的最长子串长度。

## 思路

1. **滑动窗口**：右扩，若字符重复则左缩到重复字符上次出现位置之后；维护 `last[ch]`。

## 复杂度

| 解法 | 时间 | 空间 |
|------|------|------|
| 滑动窗口 | O(n) | O(min(n, Σ)) |

## 陷阱与注意

- 字符集可能含 ASCII 以外；Python 用 `dict`，C++ 可用 `array`/`unordered_map`。

## 相关题目

- LeetCode 159、340（至多 K 个不同字符）
