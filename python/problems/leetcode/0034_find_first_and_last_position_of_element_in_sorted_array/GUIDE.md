# LeetCode 34 — Find First and Last Position of Element in Sorted Array

## 题面

- **来源**：LeetCode 34
- **链接**：<https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/>
- **简述**：在升序数组中查找目标值的开始与结束下标；不存在返回 `[-1,-1]`。

## 思路

两次二分：`bisect_left(target)` 与 `bisect_right(target)-1`，再校验该位置元素是否等于 `target`。

## 复杂度

时间 O(log n)，空间 O(1)。
