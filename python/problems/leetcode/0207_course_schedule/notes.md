# LeetCode 207 — Course Schedule（课程表）

## 题面

- **来源**：LeetCode 207
- **链接**：<https://leetcode.cn/problems/course-schedule/>
- **简述**：判断给定先修关系下是否能修完所有课程（无环）。

## 思路

**Kahn 拓扑排序**：入度为 0 入队，弹出时将后继入度减 1；若处理节点数等于 `n` 即无环。

## 复杂度

时间 O(V+E)，空间 O(V+E)。
