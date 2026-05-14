# LeetCode 22 — Generate Parentheses（括号生成）

## 题面

- **来源**：LeetCode 22
- **链接**：<https://leetcode.cn/problems/generate-parentheses/>
- **简述**：生成 `n` 对括号的所有合法组合。

## 思路

回溯：维护已放左括号数 `open`、右括号数 `close`，`open < n` 可放 `(`，`close < open` 可放 `)`。

## 复杂度

答案数为 Catalan 量级；构造时间近似与输出规模相关。
