# LeetCode 542 — 01 Matrix（01 矩阵）

## 题面

- **链接**：<https://leetcode.cn/problems/01-matrix/>
- **简述**：01 矩阵，求每个 `1` 到最近 `0` 的曼哈顿距离。

## 思路

多源 BFS：所有 `0` 同时入队，按层扩展填距离。

## 复杂度

时间 O(mn)，空间 O(mn)。

## 仓库专题

[`graph_traversal`](../../../algorithms/graph/traversal/)（BFS）；对照 [0994](../0994_rotting_oranges/) 多源扩散。
