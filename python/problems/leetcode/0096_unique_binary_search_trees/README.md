# LeetCode 96 — Unique Binary Search Trees（不同的二叉搜索树）

## 题面

- **来源**：LeetCode 96
- **链接**：<https://leetcode.cn/problems/unique-binary-search-trees/>
- **简述**：节点值为 `1..n`，求互不相同的 BST 形态总数。

## 思路

卡塔兰数 DP：`G[n] = Σ G[i-1] * G[n-i]`，`G[0]=G[1]=1`。

## 复杂度

时间 O(n²)，空间 O(n)。
