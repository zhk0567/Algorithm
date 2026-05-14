# LeetCode 23 — Merge k Sorted Lists（合并 K 个升序链表）

## 题面

- **来源**：LeetCode 23
- **链接**：<https://leetcode.cn/problems/merge-k-sorted-lists/>
- **简述**：合并 `k` 个升序链表为单个升序链表。

## 思路

**最小堆**：把每条链表头入堆，每次弹出最小并把它的 `next` 入堆。Python `heapq` 比较元组 `(val, index, node)` 避免节点不可比。

## 复杂度

时间 O(N log k)（N 为总节点数），空间 O(k)。
