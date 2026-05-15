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

## 边界

- `capacity < 1` 构造抛 `ValueError`。
- 空缓存 `get` 返回 `-1`；`capacity=1` 时第二次 `put` 淘汰首项。
- 与题解 [`0146_lru_cache`](../../../problems/leetcode/0146_lru_cache/) 行为对齐（键更新不增容量）。

## 与 C++

[`cpp/interview/classic/lru_cache/`](../../../../cpp/interview/classic/lru_cache/)

## 面试要点

- **适用场景**：缓存淘汰、页面置换、CDN/本地缓存；面试高频手写题。
- **复杂度**：`get`/`put` O(1)；空间 O(capacity)。
- **LeetCode**：[`0146_lru_cache`](../../../problems/leetcode/0146_lru_cache/)（`OrderedDict` 版）；本目录为 **哈希 + 双向链表** 手写对照。
- **常见坑**：更新已存在 key 只改值也要 **移到头部**；容量 0/1 边界；线程安全需再加锁（面试常问「如何做成线程安全」→ 分段锁或单锁包一层）。
