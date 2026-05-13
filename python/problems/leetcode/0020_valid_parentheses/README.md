# LeetCode 20 — Valid Parentheses（有效的括号）

## 题面

- **来源**：LeetCode 20
- **链接**：<https://leetcode.cn/problems/valid-parentheses/>
- **简述**：仅含 `()[]{}` 的字符串，判断是否合法配对。

## 思路

栈：左括号入栈；右括号与栈顶匹配则弹出，否则非法；结束栈空。

## 复杂度

O(n) 时间，O(n) 空间。

## 陷阱与注意

- 右括号来时栈不能为空。
- 遍历结束必须栈空。

## 相关题目

- LeetCode 32（最长有效括号）
