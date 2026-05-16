# 树状数组（Fenwick / BIT）

## 简介

利用 `i & -i` 跳 lowbit，维护前缀和；支持单点加、前缀和 O(log n)。

## 操作与复杂度

| 操作 | 时间 |
|------|------|
| `add(i, delta)` | O(log n) |
| `prefix_sum(i)` | O(log n) |
| 区间和 `[l,r]` | O(log n) |

## 区间加 + 单点查（RUPQ）

对差分数组 `d` 做 BIT：`range_add(l,r,v)` 等价于 `add(l,v); add(r+1,-v)`；点 `i` 的值 = `prefix_sum(i)`。代码中 `FenwickRUPQ` 演示。

## 典型应用

逆序对、动态前缀和、配合离散化。仓库题解对照：[LC 307 区域和检索 - 可变](../../../problems/leetcode/0307_range_sum_query_mutable/)（本题 `solution` 以树状数组实现；可与本专题线段树思路对照）。

## 代码要点

内部使用 **1-based** 下标更简洁；`n` 为 BIT 长度。
