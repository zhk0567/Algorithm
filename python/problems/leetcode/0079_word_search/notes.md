# LeetCode 79 — Word Search（单词搜索）

## 题面

- **来源**：LeetCode 79
- **链接**：<https://leetcode.cn/problems/word-search/>
- **简述**：判断字符矩阵中是否存在与 `word` 相同的路径（4 方向，不重复用同一格）。

## 思路

回溯 DFS：每格尝试作为起点，递归 4 方向匹配；用「修改原格为哨兵」标记访问，回溯时还原。

## 复杂度

最坏 O(mn · 4^L)（L 为 `word` 长度），空间 O(L)。
