# LeetCode 994 — Rotting Oranges（腐烂的橘子）

## 题面

- **链接**：<https://leetcode.cn/problems/rotting-oranges/>
- **简述**：`2` 腐烂、`1` 新鲜、`0` 空；每分钟四向传染，求最少分钟数，无法传染完则 `-1`。

## 思路

多源 BFS：初始将所有 `2` 入队，按层扩展感染 `1`。

## 复杂度

时间 O(mn)，空间 O(mn)。

## 仓库专题

[`graph_traversal`](../../../algorithms/graph/traversal/)（BFS）。
