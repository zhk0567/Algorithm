# LeetCode 46 — Permutations（全排列）

## 题面

- **来源**：LeetCode 46
- **链接**：<https://leetcode.cn/problems/permutations/>
- **简述**：返回 `nums`（不含重复）的所有全排列。

## 思路

回溯：维护 `used` 数组，递归选未选过的元素。

## 复杂度

时间 O(n · n!)，空间 O(n)。
