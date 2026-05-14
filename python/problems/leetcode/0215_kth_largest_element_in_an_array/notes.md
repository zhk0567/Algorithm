# LeetCode 215 — Kth Largest Element in an Array（数组中的第 K 个最大元素）

## 题面

- **来源**：LeetCode 215
- **链接**：<https://leetcode.cn/problems/kth-largest-element-in-an-array/>
- **简述**：返回未排序数组中第 `k` 大的元素。

## 思路

**小顶堆**：长度保持 `k`，遍历完堆顶即第 `k` 大。也可写快速选择 O(n) 平均。

## 复杂度

堆解法 O(n log k)，空间 O(k)。
