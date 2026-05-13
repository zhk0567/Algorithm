# LeetCode 287 — Find the Duplicate Number（寻找重复数）

## 题面

- **来源**：LeetCode 287
- **链接**：<https://leetcode.cn/problems/find-the-duplicate-number/>
- **简述**：长 `n+1` 的数组中元素取值 `[1,n]`，存在且仅存在一个重复值，找出它。**不能修改数组**且 **O(1) 额外空间**。

## 思路

**Floyd 判圈**：把数组视作函数 `f(i) = nums[i]`，重复值形成环；快慢指针找入环点。

## 复杂度

时间 O(n)，空间 O(1)。
