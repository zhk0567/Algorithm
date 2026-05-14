# LeetCode 84 — Largest Rectangle in Histogram（柱状图中最大的矩形）

## 题面

- **来源**：LeetCode 84
- **链接**：<https://leetcode.cn/problems/largest-rectangle-in-histogram/>
- **简述**：直方图中最大的矩形面积。

## 思路

单调递增栈：每根柱被弹出时，它就是栈中残留矩形的高，宽 = `i - stack[-1] - 1`。末尾追加 `0` 哨兵简化清空逻辑。

## 复杂度

时间 O(n)，空间 O(n)。
