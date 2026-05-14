# LeetCode 237 — Delete Node in a Linked List（删除链表中的节点）

## 题面

- **来源**：LeetCode 237
- **链接**：<https://leetcode.cn/problems/delete-node-in-a-linked-list/>
- **简述**：给定要删的节点（**不是尾节点**），不给头节点，直接删除该节点。

## 思路

把下一个节点的值拷贝过来，再把自己的 `next` 指向 `next.next`。

## 复杂度

时间 O(1)，空间 O(1)。
