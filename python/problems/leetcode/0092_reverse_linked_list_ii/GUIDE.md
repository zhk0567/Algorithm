# LeetCode 92 — Reverse Linked List II（反转链表 II）

## 题面

- **来源**：LeetCode 92
- **链接**：<https://leetcode.cn/problems/reverse-linked-list-ii/>
- **简述**：反转链表中 `[left, right]` 区间的节点。

## 思路

哑节点 + 头插法：定位 `pre` 为 `left-1` 位置，把 `cur.next` 依次插到 `pre` 之后。

## 复杂度

时间 O(n)，空间 O(1)。
