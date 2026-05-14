# LeetCode 72 — Edit Distance（编辑距离）

## 题面

- **来源**：LeetCode 72
- **链接**：<https://leetcode.cn/problems/edit-distance/>
- **简述**：求把 `word1` 变为 `word2` 的最少插入/删除/替换次数。

## 思路

二维 DP：`dp[i][j]` 表示 `word1[:i]` 变 `word2[:j]` 的最小代价。

- 边界：`dp[i][0]=i`，`dp[0][j]=j`。
- 转移：若 `word1[i-1]==word2[j-1]`，`dp[i][j]=dp[i-1][j-1]`；否则取 `min(替换, 删除, 插入) + 1`。

## 复杂度

时间 O(mn)，空间 O(mn)（可用滚动数组优化到 O(n)）。
