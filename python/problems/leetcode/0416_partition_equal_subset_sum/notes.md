# LeetCode 416 — Partition Equal Subset Sum（分割等和子集）

## 题面

- **来源**：LeetCode 416
- **链接**：<https://leetcode.cn/problems/partition-equal-subset-sum/>
- **简述**：能否把数组分成两个和相等的子集。

## 思路

转为 0/1 背包：目标 `target = total/2`。`dp[x]` 表示是否可凑出和 `x`，倒序更新。

## 复杂度

时间 O(n · target)，空间 O(target)。
