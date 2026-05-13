# LeetCode 283 — Move Zeroes（移动零）

## 题面

- **来源**：LeetCode 283
- **链接**：<https://leetcode.cn/problems/move-zeroes/>
- **简述**：原地把所有 0 移到末尾，非零保持相对顺序。

## 思路

双指针：`w` 写指针指向下一个非零落点；遍历 `i`，遇到非零写入并 `w+=1`；最后把 `[w:]` 填 0。

## 复杂度

时间 O(n)，空间 O(1)。
