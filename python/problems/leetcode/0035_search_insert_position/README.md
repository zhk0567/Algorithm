# LeetCode 35 — Search Insert Position（搜索插入位置）

## 题面

- **来源**：LeetCode 35
- **链接**：<https://leetcode.cn/problems/search-insert-position/>
- **简述**：升序无重复数组，目标存在则返回其下标；否则返回应插入位置。

## 思路

二分 `bisect_left`：返回首个 `>= target` 的位置。

## 复杂度

时间 O(log n)，空间 O(1)。
