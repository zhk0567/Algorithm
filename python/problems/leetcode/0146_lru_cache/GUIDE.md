# LeetCode 146 — LRU Cache（LRU 缓存）

## 题面

- **来源**：LeetCode 146
- **链接**：<https://leetcode.cn/problems/lru-cache/>
- **简述**：实现 `get` / `put` 均为 O(1) 的最近最少使用缓存。

## 思路

**哈希表 + 双向链表**：哈希表存 key 到节点的指针；双向链表头为最近使用、尾为最久未使用。

- Python 也可以直接借 `collections.OrderedDict`（`move_to_end` / `popitem(last=False)`）。

## 复杂度

`get` / `put` 均 O(1)，空间 O(capacity)。
