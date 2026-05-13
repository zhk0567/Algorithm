# LeetCode 234 — Palindrome Linked List（回文链表）

## 题面

- **来源**：LeetCode 234
- **链接**：<https://leetcode.cn/problems/palindrome-linked-list/>
- **简述**：判断单链表是否回文，要求 O(n) 时间、O(1) 空间。

## 思路

快慢指针找到中点 → 反转后半段 → 与前半段逐节点比较。

## 复杂度

时间 O(n)，空间 O(1)。
