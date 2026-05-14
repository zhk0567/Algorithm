# LeetCode 21 — Merge Two Sorted Lists（合并两个有序链表）

## 题面

- **来源**：LeetCode 21
- **链接**：<https://leetcode.cn/problems/merge-two-sorted-lists/>
- **简述**：升序链表 `list1`、`list2`，合并为一个升序链表。

## 思路

哑节点 + 比较头结点较小者接到结果；某一链耗尽则接上另一链剩余。

## 复杂度

O(m+n) 时间，O(1) 额外空间。

## 相关题目

- LeetCode 23（合并 K 个升序链表）
