# LeetCode 307 — Range Sum Query - Mutable

## 题面

- **链接**：<https://leetcode.cn/problems/range-sum-query-mutable/>
- **简述**：数组支持单点修改与区间 `[left, right]` 求和。

## 思路

**树状数组（Fenwick）** 或线段树均可 O(log n)；本题用 BIT：单点 `update` 为差分加在对应下标，`sumRange` 为两前缀和之差。

## 复杂度

每次 `update` / `sumRange` 为 O(log n)，空间 O(n)。

## 仓库专题

[`fenwick_tree`](../../../data_structures/tree/fenwick_tree/fenwick_tree.py)、[`segment_tree`](../../../data_structures/tree/segment_tree/segment_tree.py)（线段树为同题另一写法）。
