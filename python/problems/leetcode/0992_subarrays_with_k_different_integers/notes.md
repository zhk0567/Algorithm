# LeetCode 992 — Subarrays with K Different Integers

## 题面

- **链接**：<https://leetcode.cn/problems/subarrays-with-k-different-integers/>
- **简述**：统计恰好含 `k` 种不同整数的连续子数组个数。

## 思路

转化为「至多 k 种」：`atMost(k) - atMost(k-1)`，滑动窗口维护种类数。

## 复杂度

时间 O(n)，空间 O(k)。

## 仓库专题

[`sliding_window`](../../../algorithms/sliding_window/sliding_window.py)。
