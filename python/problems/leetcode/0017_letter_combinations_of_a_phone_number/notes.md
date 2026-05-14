# LeetCode 17 — Letter Combinations of a Phone Number（电话号码字母组合）

## 题面

- **来源**：LeetCode 17
- **链接**：<https://leetcode.cn/problems/letter-combinations-of-a-phone-number/>
- **简述**：给定仅含 `2-9` 的数字串，返回所有可能的字母组合（手机九宫格映射）。

## 思路

回溯：按位枚举该按键对应的所有字符，递归到末尾把当前串加入结果。空串特判返回 `[]`。

## 复杂度

时间 O(4ⁿ · n)，空间 O(n)。
