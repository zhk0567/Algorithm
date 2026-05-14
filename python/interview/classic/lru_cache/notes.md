# 手写 LRU Cache

> 与 [problems/leetcode/0146_lru_cache/](../../../problems/leetcode/0146_lru_cache/) 的 `OrderedDict` 版互为对照：这里 **手写** 双向链表 + 哈希，不依赖 `collections.OrderedDict`。

## 复杂度

- `get` / `put` 均 O(1)
- 空间 O(capacity)

## 设计要点

- **哈希表**：`key -> Node*`，O(1) 命中。
- **双向链表**：维护使用顺序，头侧最近、尾侧最久未用；带头尾哨兵节点免除边界判断。
- `put` 时若超出容量，剔除尾哨兵前一个节点；命中或更新均移动到头侧。

## 复用

`data_structures/advanced/lru_cache.py` 提供基础版；这里更强调可读的手写实现与单元自测。
