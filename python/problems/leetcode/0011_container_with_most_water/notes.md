# LeetCode 11 — Container With Most Water（盛最多水的容器）

## 题面

- **来源**：LeetCode 11
- **链接**：<https://leetcode.cn/problems/container-with-most-water/>
- **简述**：数组高度表示竖线，选两线与 x 轴围成容器，求最大水量。

## 思路

双指针首尾，每次移动较短一侧：更矮边限制了面积，只有换更高边才可能更大。

## 复杂度

时间 O(n)，空间 O(1)。
