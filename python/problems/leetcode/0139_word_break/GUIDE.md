# LeetCode 139 — Word Break（单词拆分）

## 题面

- **来源**：LeetCode 139
- **链接**：<https://leetcode.cn/problems/word-break/>
- **简述**：判断字符串能否被字典中的单词拼接而成（每个单词可复用）。

## 思路

线性 DP：`dp[i]` 表示 `s[:i]` 可被拼出。转移：枚举末段起点 `j`，若 `dp[j] && s[j:i] in dict` 则 `dp[i]=True`。

## 复杂度

时间 O(n²)（哈希查找平均 O(1)），空间 O(n)。
