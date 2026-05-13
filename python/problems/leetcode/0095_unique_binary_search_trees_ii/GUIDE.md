# LeetCode 95 — Unique Binary Search Trees II（不同的二叉搜索树 II）

## 题面

- **来源**：LeetCode 95
- **链接**：<https://leetcode.cn/problems/unique-binary-search-trees-ii/>
- **简述**：返回 `1..n` 能构成的所有结构不同的 BST。

## 思路

递归：枚举根 `i`，左子树由 `[l, i-1]` 生成，右子树由 `[i+1, r]` 生成；笛卡尔积组合左右子树。

## 复杂度

输出规模为卡塔兰数级别；构造时间与其同阶。
