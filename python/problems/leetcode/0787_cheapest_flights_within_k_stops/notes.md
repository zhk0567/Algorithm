# LeetCode 787 — Cheapest Flights Within K Stops（K 站中转内最便宜的航班）

## 题面

- **链接**：<https://leetcode.cn/problems/cheapest-flights-within-k-stops/>
- **简述**：最多经停 `k` 次（路径边数 ≤ k+1），求 `src` 到 `dst` 最小费用。

## 思路

Bellman–Ford 思想：做 `k+1` 轮松弛，每轮用上一轮 `dist` 更新（避免串联超过 k+1 条边）。

## 复杂度

时间 O(k·E)，空间 O(V)。

## 仓库专题

[`bellman_ford`](../../../algorithms/graph/shortest_path/bellman_ford.py)。
