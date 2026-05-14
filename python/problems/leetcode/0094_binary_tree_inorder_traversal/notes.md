# LeetCode 94 — Binary Tree Inorder Traversal（二叉树中序遍历）

## 题面

- **来源**：LeetCode 94
- **链接**：<https://leetcode.cn/problems/binary-tree-inorder-traversal/>
- **简述**：返回二叉树中序遍历值序列。

## 思路

迭代：维护栈，沿左链入栈到底，弹出访问，再转向右子。

## 复杂度

时间 O(n)，空间 O(h)。
