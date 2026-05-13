# LeetCode 37 — Sudoku Solver（解数独）

## 题面

- **来源**：LeetCode 37
- **链接**：<https://leetcode.cn/problems/sudoku-solver/>
- **简述**：原地求解 9x9 数独，保证解唯一。

## 思路

回溯 + 位掩码：维护每行/每列/每 3x3 宫的可用数集（`bit`），按空格回溯尝试。

## 复杂度

理论指数级；实际 9x9 配合剪枝在毫秒级。
