# LeetCode 8 — String to Integer (atoi)（字符串转换整数）

## 题面

- **来源**：LeetCode 8
- **链接**：<https://leetcode.cn/problems/string-to-integer-atoi/>
- **简述**：忽略前导空白，识别可选正负号，读取连续数字直到非法字符；结果钳制到 32 位有符号整型。

## 思路

线性扫描 + 提前钳制以防溢出（C++ 用 `long long` 也可）。

## 复杂度

时间 O(n)，空间 O(1)。
