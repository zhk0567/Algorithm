# LeetCode 355 — Design Twitter

## 题面

- **链接**：<https://leetcode.cn/problems/design-twitter/>
- **简述**：发帖、关注/取关、拉取自己和关注者最近 10 条推文。

## 思路

每用户推文按时间递增存储；`getNewsFeed` 对关注列表做「多路归并」取前 10（小顶堆按时间取最大）。

## 复杂度

发帖 O(1)；拉取 O(F·log F + 10 log F)，F 为关注人数。

## 仓库专题

[`heap`](../../../data_structures/tree/heap/heap.py)、[`hash_table`](../../../data_structures/linear/hash_table/hash_table.py)。
