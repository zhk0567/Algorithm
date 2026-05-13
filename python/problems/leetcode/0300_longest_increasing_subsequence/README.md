# LeetCode 300 — Longest Increasing Subsequence（最长递增子序列）

## 题面

- **来源**：LeetCode 300
- **链接**：<https://leetcode.cn/problems/longest-increasing-subsequence/>
- **简述**：求严格递增子序列的最大长度。

## 思路

**O(n log n) 二分**：维护 `tails`，`tails[k]` 为长度为 `k+1` 的递增子序列的最小末尾。

- 遍历 `x`：在 `tails` 中找首个 `>= x` 的位置（`bisect_left`），替换或追加。
- `len(tails)` 即答案。

## 复杂度

时间 O(n log n)，空间 O(n)。
