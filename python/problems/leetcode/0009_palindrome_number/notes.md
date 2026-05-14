# LeetCode 9 — Palindrome Number（回文数）

## 题面

- **来源**：LeetCode 9
- **链接**：<https://leetcode.cn/problems/palindrome-number/>
- **简述**：判断整数是否为回文；不得转为字符串（可选约束，本实现用反转半段）。

## 思路

负数或末位为 0 且非 0 则 false；反复 `x % 10` 构造反转的后半段，长度奇偶处理。

## 复杂度

时间 O(log n)，空间 O(1)。
