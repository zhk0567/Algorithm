# LeetCode 437 — Path Sum III（路径总和 III）

## 题面

- **来源**：LeetCode 437
- **链接**：<https://leetcode.cn/problems/path-sum-iii/>
- **简述**：求二叉树中和为 `targetSum` 的路径数；路径方向向下、起止不限于根/叶。

## 思路

**前缀和 + 哈希**：DFS 维护从根到当前节点的累计和 `cur`，查 `prefix[cur-target]` 次数累加；回溯时减回。

## 复杂度

时间 O(n)，空间 O(n)。
