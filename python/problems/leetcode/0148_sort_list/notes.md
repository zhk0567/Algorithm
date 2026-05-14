# LeetCode 148 — Sort List（排序链表）

## 题面

- **来源**：LeetCode 148
- **链接**：<https://leetcode.cn/problems/sort-list/>
- **简述**：O(n log n) 时间、常数级空间地对链表升序排序。

## 思路

**自顶向下归并**：快慢指针找中点拆两半，递归排序后合并。空间 O(log n) 递归栈；若严格 O(1) 空间需自底向上迭代归并。

## 复杂度

时间 O(n log n)，空间 O(log n)。
