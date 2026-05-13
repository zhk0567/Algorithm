# LeetCode 18 — 4Sum（四数之和）

## 题面

- **来源**：LeetCode 18
- **链接**：<https://leetcode.cn/problems/4sum/>
- **简述**：找出所有不重复的四元组 `(a,b,c,d)` 使得 `a+b+c+d == target`。

## 思路

排序后双层循环固定前两个数，余下双指针；逐层用相邻去重剪枝。

## 复杂度

时间 O(n³)，空间 O(1)（不计输出）。
