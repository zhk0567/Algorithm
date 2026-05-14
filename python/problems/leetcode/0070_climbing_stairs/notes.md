# LeetCode 70 — Climbing Stairs（爬楼梯）

## 题面

- **来源**：LeetCode 70
- **链接**：<https://leetcode.cn/problems/climbing-stairs/>
- **简述**：每次可爬 1 或 2 阶，求爬到 `n` 阶方案数。

## 思路

斐波那契：`f(n)=f(n-1)+f(n-2)`，滚动数组 O(1) 空间。

## 复杂度

O(n) 时间，O(1) 空间。

## 相关题目

- LeetCode 746（使用最小花费爬楼梯）
