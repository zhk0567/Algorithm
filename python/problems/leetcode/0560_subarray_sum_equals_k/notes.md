# LeetCode 560 — Subarray Sum Equals K（和为 K 的子数组）

## 题面

- **来源**：LeetCode 560
- **链接**：<https://leetcode.cn/problems/subarray-sum-equals-k/>
- **简述**：返回和等于 `k` 的连续子数组个数。

## 思路

前缀和 + 哈希表：扫描时记录每个前缀和出现次数；对当前前缀 `s`，累加 `cnt[s-k]`。

## 复杂度

时间 O(n)，空间 O(n)。
