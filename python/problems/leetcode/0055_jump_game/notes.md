# LeetCode 55 — Jump Game（跳跃游戏）

## 题面

- **来源**：LeetCode 55
- **链接**：<https://leetcode.cn/problems/jump-game/>
- **简述**：每个元素表示从该位置最远可跳步数，判断能否到达末尾。

## 思路

贪心：维护可达最远下标 `far`，遍历时若 `i > far` 则不可达；否则 `far = max(far, i+nums[i])`，一旦 `far >= n-1` 立即返回。

## 复杂度

时间 O(n)，空间 O(1)。
