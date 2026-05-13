# LeetCode 98 — Validate Binary Search Tree（验证二叉搜索树）

## 题面

- **来源**：LeetCode 98
- **链接**：<https://leetcode.cn/problems/validate-binary-search-tree/>
- **简述**：判断给定二叉树是否为有效 BST。

## 思路

递归带上下界：左子树上界改为当前节点值，右子树下界改为当前节点值，严格不等。

## 复杂度

时间 O(n)，空间 O(h)。
