# LeetCode 78 — Subsets（子集）

## 题面

- **来源**：LeetCode 78
- **链接**：<https://leetcode.cn/problems/subsets/>
- **简述**：返回 `nums`（不含重复元素）的所有子集。

## 思路

回溯：每个位置选/不选，递归到末尾收集；或迭代：对已有结果集合，依次往里追加新元素。

## 复杂度

时间 O(n · 2ⁿ)，空间 O(n)。
