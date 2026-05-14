# LeetCode 239 — Sliding Window Maximum（滑动窗口最大值）

## 题面

- **来源**：LeetCode 239
- **链接**：<https://leetcode.cn/problems/sliding-window-maximum/>
- **简述**：长度为 `k` 的窗口在数组上滑动，输出每个窗口的最大值。

## 思路

**单调递减双端队列**：存下标。

- 入队前弹出所有不大于当前值的尾部下标（保持单调）；
- 队首过期（下标 ≤ `i-k`）弹出；
- `i >= k-1` 时记录队首对应值。

## 复杂度

时间 O(n)，空间 O(k)。
