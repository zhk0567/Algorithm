# LeetCode 169 — Majority Element（多数元素）

## 题面

- **来源**：LeetCode 169
- **链接**：<https://leetcode.cn/problems/majority-element/>
- **简述**：返回数组中出现次数 `> n/2` 的元素（题目保证存在）。

## 思路

**Boyer–Moore 投票**：维护候选 `cand` 与计数 `cnt`；同则 `cnt+=1`，否则 `cnt-=1`，归零换候选。

## 复杂度

时间 O(n)，空间 O(1)。
