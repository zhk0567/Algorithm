# 手写 LFU Cache（O(1)）

> LeetCode 460。每个键有访问频次 `freq`；满时淘汰频次最少者，频次相同则淘汰最久未用。

## 设计

- `kv`: `key -> Node(key, val, freq)`
- `freq_list`: `freq -> OrderedDict`（按插入顺序的频次桶；这里手写 **双向链表桶** 避免依赖 `OrderedDict.popitem`）
- `min_freq`: 当前最小频次

`get`/`put` 命中后频次 +1，从旧桶移除、加入新桶；插入新 key 时频次置 1，`min_freq = 1`；淘汰从 `freq_list[min_freq]` 队尾取。

## 复杂度

`get` / `put` 均 O(1)，空间 O(capacity)。
