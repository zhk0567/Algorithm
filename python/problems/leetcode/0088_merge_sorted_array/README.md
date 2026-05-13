# LeetCode 88 — Merge Sorted Array（合并两个有序数组）

## 题面

- **来源**：LeetCode 88
- **链接**：<https://leetcode.cn/problems/merge-sorted-array/>
- **简述**：把 `nums2`（长 `n`）原地合并到 `nums1`（长 `m+n`，后 `n` 位为 0 占位）保持升序。

## 思路

从后向前三指针：避免覆盖未读元素。

## 复杂度

时间 O(m+n)，空间 O(1)。
