# LeetCode 155 — Min Stack（最小栈）

## 题面

- **来源**：LeetCode 155
- **链接**：<https://leetcode.cn/problems/min-stack/>
- **简述**：实现支持 O(1) 的 `push`、`pop`、`top`、`getMin` 的栈。

## 思路

辅助栈：与主栈同步入栈/出栈，存当前最小（取自身或栈顶最小中的较小者）。

## 复杂度

所有操作 O(1)，空间 O(n)。
