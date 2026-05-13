# LeetCode 406 — Queue Reconstruction by Height（根据身高重建队列）

## 题面

- **来源**：LeetCode 406
- **链接**：<https://leetcode.cn/problems/queue-reconstruction-by-height/>
- **简述**：`people[i] = [h, k]`，重建队列使每个 `h_i` 之前恰有 `k_i` 个不矮于自己的人。

## 思路

按 `h` 降序、`k` 升序排序；逐个按 `k` 插入到结果数组的下标 `k`。

## 复杂度

时间 O(n²)（列表 `insert`），空间 O(n)。
