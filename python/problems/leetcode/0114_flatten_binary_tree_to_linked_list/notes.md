# LeetCode 114 — Flatten Binary Tree to Linked List（二叉树展开为链表）

## 题面

- **来源**：LeetCode 114
- **链接**：<https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/>
- **简述**：把二叉树原地展开为按先序排列的、仅用右孩子的链表。

## 思路

**Morris 风格**：对每个节点，若有左子树，找到左子树最右节点，让它的 `right` 指向当前节点的 `right`；再把左子树挪到右；移动到 `right`。

## 复杂度

时间 O(n)，空间 O(1)。
