# LeetCode 2 — Add Two Numbers（两数相加）

## 题面

- **来源**：LeetCode 2
- **链接**：<https://leetcode.cn/problems/add-two-numbers/>
- **简述**：两链表低位在前表示整数，求和链表。

## 思路

模拟进位，同时遍历两链；注意末尾进位。

## 复杂度

O(max(m,n)) 时间，O(1) 额外空间（不计结果）。

## 编译运行

```powershell
Set-Location cpp\problems\leetcode\0002_add_two_numbers
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe solution.cpp
.\run.exe
```
