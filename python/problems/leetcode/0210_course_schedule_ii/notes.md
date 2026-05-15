# LeetCode 210 — Course Schedule II（课程表 II）

## 题面

- **链接**：<https://leetcode.cn/problems/course-schedule-ii/>
- **简述**：与 207 相同依赖关系，输出一种合法修课顺序；有环则 `[]`。

## 思路

Kahn 拓扑排序：入度为 0 入队，依次弹出并减邻居入度。

## 复杂度

时间 O(V+E)，空间 O(V+E)。

## 仓库专题

[`kahn`](../../../algorithms/graph/topological_sort/kahn.py)；判环见 [0207](../0207_course_schedule/)。
