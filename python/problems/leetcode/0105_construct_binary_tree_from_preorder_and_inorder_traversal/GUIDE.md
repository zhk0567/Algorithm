# LeetCode 105 — Construct Binary Tree from Preorder and Inorder Traversal

## 题面

- **来源**：LeetCode 105
- **链接**：<https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/>
- **简述**：根据前序与中序遍历序列重建二叉树（节点值唯一）。

## 思路

`preorder[0]` 是当前根，按中序中的根位置切分左/右子区间递归。预先把「中序值 -> 下标」存入哈希表加速定位。

## 复杂度

时间 O(n)，空间 O(n)。
