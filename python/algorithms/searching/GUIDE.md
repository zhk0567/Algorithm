# 查找（Searching）

## 简介

在有序或无序集合中定位元素；二分及其变体是算法面试高频。

## 操作与复杂度

| 操作 | 条件 | 时间 |
|------|------|------|
| 线性查找 | 任意 | O(n) |
| 二分查找 | 有序 | O(log n) |
| lower_bound / upper_bound | 有序 | O(log n) |

## 代码要点

`lower_bound`：第一个 `>= target` 的下标；`upper_bound`：第一个 `> target`。旋转数组二分需比较端点与 mid。
