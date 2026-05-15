# LeetCode 127 — Word Ladder

## 题面

- **链接**：<https://leetcode.cn/problems/word-ladder/>
- **简述**：每次改一个字母，从 `beginWord` 到 `endWord` 的最少步数（含首尾）。

## 思路

BFS 最短路；邻接通过「逐位替换 + 在 wordSet 中」生成。

## 复杂度

时间 O(N·L·26)，空间 O(N)。

## 仓库专题

[`graph_traversal`](../../../algorithms/graph/traversal/)（BFS）。
