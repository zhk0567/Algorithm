# LeetCode 4 — Median of Two Sorted Arrays（寻找两个正序数组的中位数）

## 题面

- **来源**：LeetCode 4
- **链接**：<https://leetcode.cn/problems/median-of-two-sorted-arrays/>
- **简述**：两个有序数组长度 `m,n`，求合并后的中位数，要求 **O(log(m+n))**。

## 思路

对较短数组做二分：划分 `i` 与 `j=(m+n+1)/2-i`，使左半最大值 ≤ 右半最小值。

## 复杂度

O(log(min(m,n))) 时间，O(1) 空间。

## 陷阱与注意

- 边界 `i=0/m`、`j=0/n` 时用正负无穷占位。
- 总长度为偶数时中位数为两中间值平均。

## 相关题目

- LeetCode 295（数据流的中位数）
