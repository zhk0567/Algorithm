# LeetCode 27 — Remove Element（移除元素）

## 题面

- **来源**：LeetCode 27
- **链接**：<https://leetcode.cn/problems/remove-element/>
- **简述**：原地删除值为 `val` 的元素，返回新长度。

## 思路

双指针：`w` 写指针，遍历时仅当 `nums[i] != val` 写入。

## 复杂度

时间 O(n)，空间 O(1)。
