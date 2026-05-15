# LeetCode 743 — Network Delay Time（网络延迟时间）

## 题面

- **链接**：<https://leetcode.cn/problems/network-delay-time/>
- **简述**：有向带权图，从节点 `k` 发出信号，求所有节点收到信号的最短时间；不可达则 `-1`。

## 思路

单源最短路（Dijkstra，边权非负）；答案为 `max(dist)`。

## 复杂度

时间 O((V+E) log V)，空间 O(V+E)。

## 仓库专题

[`dijkstra`](../../../algorithms/graph/shortest_path/dijkstra.py)。
