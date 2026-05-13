# LeetCode 32 — Longest Valid Parentheses（最长有效括号）

## 题面

- **来源**：LeetCode 32
- **链接**：<https://leetcode.cn/problems/longest-valid-parentheses/>
- **简述**：求只含 `(` `)` 的字符串中最长合法括号子串长度。

## 思路

**栈**：栈底放最后一个未匹配右括号的下标，初值 `-1`。

- 遇 `(` 入栈下标；
- 遇 `)` 先出栈，若栈空则将当前下标入栈作为新「最后未匹配」基准；否则以 `i - 栈顶` 更新答案。

## 复杂度

时间 O(n)，空间 O(n)。
