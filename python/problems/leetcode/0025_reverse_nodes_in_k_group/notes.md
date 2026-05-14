# LeetCode 25 — Reverse Nodes in k-Group（K 个一组翻转链表）

## 题面

- **来源**：LeetCode 25
- **链接**：<https://leetcode.cn/problems/reverse-nodes-in-k-group/>
- **简述**：每 `k` 个节点一组翻转，不足 `k` 个保持原序；要求 O(1) 额外空间。

## 思路

迭代：哑节点 + 组前驱 `pre`。每轮：

1. 从 `pre` 起向后数 `k` 个节点定位组尾 `tail`，不足则结束；
2. 记录下一组首 `next_grp = tail.next`，断开后对该段反转；
3. 把反转后段接回 `pre` 与 `next_grp`，更新 `pre` 为该段新尾。

## 复杂度

时间 O(n)，空间 O(1)。
