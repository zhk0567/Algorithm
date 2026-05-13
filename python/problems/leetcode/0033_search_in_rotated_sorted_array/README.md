# LeetCode 33 — Search in Rotated Sorted Array（搜索旋转排序数组）

## 题面

- **来源**：LeetCode 33
- **链接**：<https://leetcode.cn/problems/search-in-rotated-sorted-array/>
- **简述**：在一个被旋转过的升序数组中找目标值的下标，不存在返回 −1。

## 思路

二分：每次根据 `nums[mid]` 与 `nums[l]` 的关系判定 `[l, mid]` 与 `[mid, r]` 哪一段必然有序，再用 target 是否落在该有序段决定收缩方向。

## 复杂度

时间 O(log n)，空间 O(1)。
