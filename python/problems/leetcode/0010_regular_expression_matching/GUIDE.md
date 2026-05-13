# LeetCode 10 — Regular Expression Matching（正则表达式匹配）

## 题面

- **来源**：LeetCode 10
- **链接**：<https://leetcode.cn/problems/regular-expression-matching/>
- **简述**：实现支持 `.` 与 `*` 的正则匹配，`*` 匹配 0 个或多个其前一字符。

## 思路

二维 DP，`dp[i][j]` 表示 `s[:i]` 与 `p[:j]` 是否匹配。

- 若 `p[j-1] == '*'`：要么忽略 `x*`：`dp[i][j-2]`；要么 `s[i-1]` 与 `p[j-2]` 匹配则 `dp[i-1][j]`；
- 否则单字符匹配：`dp[i-1][j-1] && match(s[i-1], p[j-1])`。

## 复杂度

时间 O(mn)，空间 O(mn)。
