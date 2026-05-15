# LeetCode 600 — Non-negative Integers Without Consecutive Ones

## 题面

- **链接**：<https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/>
- **简述**：统计 `[0, n]` 中二进制表示不含连续 `1` 的整数个数。

## 思路

数位 DP：按位填 `0/1`，状态记录上一位是否为 `1`，禁止 `11`。

## 复杂度

时间 O(log n)，空间 O(log n)。

## 仓库专题

[`digit_dp`](../../../algorithms/dynamic_programming/digit/digit_dp.py)。
