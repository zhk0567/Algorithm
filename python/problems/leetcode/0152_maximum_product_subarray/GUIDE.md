# LeetCode 152 — Maximum Product Subarray（乘积最大子数组）

## 题面

- **来源**：LeetCode 152
- **链接**：<https://leetcode.cn/problems/maximum-product-subarray/>
- **简述**：连续子数组的最大乘积。

## 思路

双状态 DP：负数会让最大变最小，必须同时维护 `mx`（当前以该位结尾的最大乘积）和 `mn`（最小）：

- `mx_new = max(x, mx*x, mn*x)`
- `mn_new = min(x, mx*x, mn*x)`

## 复杂度

时间 O(n)，空间 O(1)。
