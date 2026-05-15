# LeetCode 785 — Is Graph Bipartite?（判断二分图）

## 题面

- **链接**：<https://leetcode.cn/problems/is-graph-bipartite/>
- **简述**：无向图邻接表，能否二染色（相邻不同色）。

## 思路

BFS/DFS 染色：未访问染 0，邻居染 1，冲突则非二分图。

## 复杂度

时间 O(V+E)，空间 O(V)。

## 仓库专题

[`bipartite_matching`](../../../algorithms/graph/bipartite_matching/)（最大匹配为进阶；本题仅判二分性）。
