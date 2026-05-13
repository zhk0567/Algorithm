# LeetCode 31 — Next Permutation（下一个排列）

## 题面

- **来源**：LeetCode 31
- **链接**：<https://leetcode.cn/problems/next-permutation/>
- **简述**：原地把 `nums` 替换成其字典序下一个排列；最大者下一个为最小者。

## 思路

1. 从右往左找首个 `i` 使 `nums[i] < nums[i+1]`；
2. 若存在，从右往左找首个 `j > i` 使 `nums[j] > nums[i]`，交换二者；
3. 反转 `i+1..end`。

## 复杂度

时间 O(n)，空间 O(1)。
