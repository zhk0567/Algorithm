# LeetCode 45 — Jump Game II（跳跃游戏 II）

## 题面

- **来源**：LeetCode 45
- **链接**：<https://leetcode.cn/problems/jump-game-ii/>
- **简述**：保证可达末尾，求最少跳跃次数。

## 思路

贪心：维护当前层最远可达 `end` 与下一层最远 `far`；遍历 `i < n-1`，每到 `end` 步数 +1 并把 `end = far`。

## 复杂度

时间 O(n)，空间 O(1)。
