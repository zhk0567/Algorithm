# LeetCode 1192 — Critical Connections in a Network（查找关键连接）

## 题面

- **链接**：<https://leetcode.cn/problems/critical-connections-in-a-network/>
- **简述**：无向连通图，求所有**桥**（删去后连通分量增加的无向边）。

## 思路

Tarjan：`low[v] > dfn[u]` 时边 `(u,v)` 为桥。

## 复杂度

时间 O(V+E)，空间 O(V)。

## 仓库专题

[`tarjan`](../../../algorithms/graph/scc/tarjan.py)（强连通分量；桥为同族 DFS 维护 `low`）。
