# LeetCode 380 — Insert Delete GetRandom O(1)

## 题面

- **链接**：<https://leetcode.cn/problems/insert-delete-getrandom-o1/>
- **简述**：支持均摊 O(1) 的 `insert` / `remove` / `getRandom`。

## 思路

动态数组 + 哈希表存「值 → 下标」；删除时与末尾交换再 pop。

## 复杂度

各操作均摊 O(1)。

## 仓库专题

[`hash_table`](../../../data_structures/linear/hash_table/hash_table.py)。
