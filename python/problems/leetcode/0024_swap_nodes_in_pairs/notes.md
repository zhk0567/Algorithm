# LeetCode 24 — Swap Nodes in Pairs（两两交换链表中的节点）

## 题面

- **来源**：LeetCode 24
- **链接**：<https://leetcode.cn/problems/swap-nodes-in-pairs/>
- **简述**：每两个相邻节点交换一次。

## 思路

哑节点 + 三指针 `pre, a, b`：把 `pre → a → b → c` 重排为 `pre → b → a → c`，`pre = a`。

## 复杂度

时间 O(n)，空间 O(1)。
