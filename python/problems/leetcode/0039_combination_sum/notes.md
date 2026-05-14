# LeetCode 39 — Combination Sum（组合总和）

## 题面

- **来源**：LeetCode 39
- **链接**：<https://leetcode.cn/problems/combination-sum/>
- **简述**：无重复正整数数组 `candidates`，元素可被无限次使用，求所有和为 `target` 的不重复组合。

## 思路

回溯，先排序；递归参数带 `start`，保证组合非降序避免重复；剪枝：若 `candidates[i] > remain` 直接 `break`。

## 复杂度

与解集规模相关；可达指数级。
