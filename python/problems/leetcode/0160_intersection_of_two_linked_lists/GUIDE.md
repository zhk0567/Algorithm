# LeetCode 160 — Intersection of Two Linked Lists（相交链表）

## 题面

- **来源**：LeetCode 160
- **链接**：<https://leetcode.cn/problems/intersection-of-two-linked-lists/>
- **简述**：找两条单链表的第一个公共节点；不存在返回 `None`。

## 思路

**双指针拼接法**：`a` 走完 A 走 B，`b` 走完 B 走 A，两者各走 `len(A)+len(B)` 步必同步到交点或同时为 `None`。

## 复杂度

时间 O(m+n)，空间 O(1)。
