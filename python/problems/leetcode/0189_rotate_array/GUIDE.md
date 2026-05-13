# LeetCode 189 — Rotate Array（旋转数组）

## 题面

- **来源**：LeetCode 189
- **链接**：<https://leetcode.cn/problems/rotate-array/>
- **简述**：将数组向右循环移动 `k` 位，要求原地、O(1) 额外空间。

## 思路

三次反转：先整体反转，再分别反转 `[0, k-1]` 与 `[k, n-1]`。

## 复杂度

时间 O(n)，空间 O(1)。
