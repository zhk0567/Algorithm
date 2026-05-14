# LeetCode 53 — Maximum Subarray（最大子数组和）

## 题面

- **来源**：LeetCode 53
- **链接**：<https://leetcode.cn/problems/maximum-subarray/>
- **简述**：整数数组，求连续子数组最大和。

## 思路

**Kadane**：`cur = max(x, cur + x)`，`ans = max(ans, cur)`。

## 复杂度

O(n) 时间，O(1) 空间。

## 相关题目

- LeetCode 152（乘积最大子数组）
