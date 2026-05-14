# LeetCode 124 — Binary Tree Maximum Path Sum（二叉树中的最大路径和）

## 题面

- **来源**：LeetCode 124
- **链接**：<https://leetcode.cn/problems/binary-tree-maximum-path-sum/>
- **简述**：路径可经任意节点（不可重复），求最大节点值之和。

## 思路

后序：函数返回「从当前节点向下的单边最大贡献」，并用 `当前值 + 左贡献 + 右贡献` 更新全局答案。负数贡献以 0 截断。

## 复杂度

时间 O(n)，空间 O(h)。
