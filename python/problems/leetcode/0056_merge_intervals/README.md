# LeetCode 56 — Merge Intervals（合并区间）

## 题面

- **来源**：LeetCode 56
- **链接**：<https://leetcode.cn/problems/merge-intervals/>
- **简述**：合并所有重叠区间，返回不重叠区间集合。

## 思路

按左端点排序后线性扫描：若与结果末尾区间重叠则合并右端，否则追加。

## 复杂度

时间 O(n log n)，空间 O(n)。
