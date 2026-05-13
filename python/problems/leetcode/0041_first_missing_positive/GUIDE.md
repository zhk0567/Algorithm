# LeetCode 41 — First Missing Positive（缺失的第一个正数）

## 题面

- **来源**：LeetCode 41
- **链接**：<https://leetcode.cn/problems/first-missing-positive/>
- **简述**：O(n) 时间、O(1) 额外空间求未排序数组中缺失的最小正整数。

## 思路

**原地哈希**：把 `x ∈ [1, n]` 放到下标 `x-1` 处；扫描时首个 `nums[i] != i+1` 的位置答案为 `i+1`，全对则为 `n+1`。

## 复杂度

时间 O(n)，空间 O(1)。
