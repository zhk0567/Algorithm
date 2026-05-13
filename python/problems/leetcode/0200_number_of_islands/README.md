# LeetCode 200 — Number of Islands（岛屿数量）

## 题面

- **来源**：LeetCode 200
- **链接**：<https://leetcode.cn/problems/number-of-islands/>
- **简述**：网格中 `'1'` 表陆地、`'0'` 表水，求 4-方向连通陆地的连通块数。

## 思路

逐格扫描，遇到 `'1'` 计数 + DFS 把整块淹为 `'0'`。

## 复杂度

时间 O(mn)，空间 O(mn) 递归栈最坏。
