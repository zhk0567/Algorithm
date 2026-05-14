# LeetCode 101 — Symmetric Tree（对称二叉树）

## 题面

- **来源**：LeetCode 101
- **链接**：<https://leetcode.cn/problems/symmetric-tree/>
- **简述**：判断二叉树是否轴对称。

## 思路

递归：两子树对称当且仅当 `l.val == r.val` 且 `l.left ~ r.right` 且 `l.right ~ r.left`。

## 复杂度

时间 O(n)，空间 O(h)。
