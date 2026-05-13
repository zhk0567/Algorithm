# LeetCode 142 — Linked List Cycle II（环形链表 II）

## 题面

- **来源**：LeetCode 142
- **链接**：<https://leetcode.cn/problems/linked-list-cycle-ii/>
- **简述**：若链表有环，返回入环第一个节点；否则 `None`。

## 思路

Floyd 算法：快慢指针相遇后，把其中一个回到表头，二者同速前进，再次相遇点即入环节点。

## 复杂度

时间 O(n)，空间 O(1)。
