# LeetCode 847 — Shortest Path Visiting All Nodes

## 题面

- **链接**：<https://leetcode.cn/problems/shortest-path-visiting-all-nodes/>
- **简述**：无向图，可重复经过点/边，求访问全部节点的最短路径长度。

## 思路

状态 BFS：`(当前点, 已访问集合 mask)`，从每个点作为起点多源入队。

## 复杂度

时间 O(n·2^n·(V+E))，n 较小时可行；空间同阶。

## 仓库专题

[`bitmask_dp`](../../../algorithms/dynamic_programming/bitmask/bitmask_dp.py)（状压思想）。
