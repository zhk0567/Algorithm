# LeetCode 138 — Copy List with Random Pointer

## 题面

- **链接**：<https://leetcode.cn/problems/copy-list-with-random-pointer/>
- **简述**：深拷贝带 `random` 指针的链表。

## 思路

哈希表 `原节点 → 新节点`：先创建全部新节点，再挂 `next` / `random`。

## 复杂度

时间 O(n)，空间 O(n)。

## 仓库专题

[`linked_list`](../../../data_structures/linear/linked_list/linked_list.py)。
