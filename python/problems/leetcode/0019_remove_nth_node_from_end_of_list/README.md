# LeetCode 19 — Remove Nth Node From End of List（删除链表倒数第 N 个结点）

## 题面

- **来源**：LeetCode 19
- **链接**：<https://leetcode.cn/problems/remove-nth-node-from-end-of-list/>
- **简述**：一次遍历删除倒数第 `n` 个节点。

## 思路

哑节点 + 快慢指针：`fast` 先走 `n+1` 步，再 `fast/slow` 同步走至 `fast` 为 `None`，删除 `slow.next`。

## 复杂度

时间 O(L)，空间 O(1)。
