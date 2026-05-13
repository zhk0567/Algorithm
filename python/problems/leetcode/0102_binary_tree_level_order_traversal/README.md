# LeetCode 102 — Binary Tree Level Order Traversal（二叉树的层序遍历）

## 题面

- **来源**：LeetCode 102
- **链接**：<https://leetcode.cn/problems/binary-tree-level-order-traversal/>
- **简述**：返回二叉树按层从左到右的节点值列表。

## 思路

BFS：用队列每次弹出一整层规模 `len(queue)` 的节点。

## 复杂度

时间 O(n)，空间 O(n)。
