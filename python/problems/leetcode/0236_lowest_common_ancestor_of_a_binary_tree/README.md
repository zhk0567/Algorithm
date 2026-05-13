# LeetCode 236 — Lowest Common Ancestor of a Binary Tree（二叉树的最近公共祖先）

## 题面

- **来源**：LeetCode 236
- **链接**：<https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/>
- **简述**：给定二叉树和两个节点 `p`、`q`，返回它们的最近公共祖先。所有节点值唯一，且 `p`、`q` 均在树中。

## 思路

递归：

- 若当前 `root` 为 `None` 或等于 `p`、`q`，返回 `root`；
- 左右子树递归；若两侧都非空，当前节点即 LCA；否则返回非空一侧。

## 复杂度

时间 O(n)，空间 O(h)。
