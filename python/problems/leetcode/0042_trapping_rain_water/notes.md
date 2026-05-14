# LeetCode 42 — Trapping Rain Water（接雨水）

## 题面

- **来源**：LeetCode 42
- **链接**：<https://leetcode.cn/problems/trapping-rain-water/>
- **简述**：非负整数数组表示柱状图高度，求能接的雨水总量。

## 思路

**双指针**：维护左右两侧当前最大高度 `lm`/`rm`，向中间移动较短一侧，该侧「当前柱」若低于本侧最大则可蓄水 `max - h[i]`。

## 复杂度

时间 O(n)，空间 O(1)。
