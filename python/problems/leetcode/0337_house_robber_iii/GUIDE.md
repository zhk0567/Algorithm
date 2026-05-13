# LeetCode 337 — House Robber III（打家劫舍 III）

## 题面

- **来源**：LeetCode 337
- **链接**：<https://leetcode.cn/problems/house-robber-iii/>
- **简述**：二叉树结构上做不可相邻打劫，求最大金额。

## 思路

后序：每个节点返回二元组 `(steal, skip)`。

- `steal = node.val + l_skip + r_skip`
- `skip = max(l_steal, l_skip) + max(r_steal, r_skip)`

## 复杂度

时间 O(n)，空间 O(h)。
