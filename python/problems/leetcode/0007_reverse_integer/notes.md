# LeetCode 7 — Reverse Integer（整数反转）

## 题面

- **来源**：LeetCode 7
- **链接**：<https://leetcode.cn/problems/reverse-integer/>
- **简述**：将 32 位有符号整数各位反转；溢出则返回 0。

## 思路

反复 `pop = x % 10`，`x //= 10`，`rev = rev * 10 + pop`，在乘加前检查是否越界 `[−2³¹, 2³¹−1]`。

## 复杂度

时间 O(log|x|)，空间 O(1)。
