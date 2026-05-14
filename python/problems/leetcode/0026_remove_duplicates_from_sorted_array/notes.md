# LeetCode 26 — Remove Duplicates from Sorted Array（删除有序数组中的重复项）

## 题面

- **来源**：LeetCode 26
- **链接**：<https://leetcode.cn/problems/remove-duplicates-from-sorted-array/>
- **简述**：原地删除重复，使每个元素最多出现一次，返回新长度 `k`。

## 思路

双指针：`slow` 指向下一个写入位置，遍历 `fast`，若 `nums[fast] != nums[slow-1]` 则写入。

## 复杂度

时间 O(n)，空间 O(1)。
