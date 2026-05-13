# LeetCode 238 — Product of Array Except Self（除自身以外数组的乘积）

## 题面

- **来源**：LeetCode 238
- **链接**：<https://leetcode.cn/problems/product-of-array-except-self/>
- **简述**：返回 `output[i] = ∏ nums[j], j ≠ i`，要求 O(n) 且不使用除法。

## 思路

两次扫描：先用 `output[i]` 存「左前缀积」，再用一个变量 `right` 从右往左累乘并把 `output[i] *= right`。

## 复杂度

时间 O(n)，输出外空间 O(1)。
