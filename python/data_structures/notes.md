# 数据结构（Python）

> **全库覆盖盘点**（与 `algorithms/` 边界、缺口队列）：[算法覆盖总表](../../README.md#coverage)。

| 子目录 | 内容 |
|--------|------|
| `linear/` | 数组、链表、栈、队列、双端队列、哈希表 |
| `tree/` | 二叉树、BST、AVL、**红黑树**、Trie、线段树、树状数组、堆 |
| `graph/` | 邻接表、邻接矩阵、并查集 |
| `advanced/` | 跳表、布隆过滤器、LRU 等 |

## 已实现清单（第一阶段）

- [x] `linear/array` — `dynamic_array.py`
- [x] `linear/linked_list` — `linked_list.py`
- [x] `linear/stack` — `stack.py`
- [x] `linear/queue` — `queue.py`
- [x] `linear/deque` — `deque.py`
- [x] `linear/hash_table` — `hash_table.py`
- [x] `tree/binary_tree` — `binary_tree.py`
- [x] `tree/bst` — `bst.py`
- [x] `tree/avl` — `avl.py`
- [x] `tree/red_black_tree` — `red_black_tree.py`
- [x] `tree/trie` — `trie.py`
- [x] `tree/segment_tree` — `segment_tree.py`
- [x] `tree/fenwick_tree` — `fenwick_tree.py`
- [x] `tree/heap` — `heap.py`
- [x] `graph/adjacency_list` — `graph_list.py`
- [x] `graph/adjacency_matrix` — `graph_matrix.py`
- [x] `graph/disjoint_set` — `union_find.py`
- [x] `advanced/skip_list` — `skip_list.py`
- [x] `advanced/bloom_filter` — `bloom_filter.py`
- [x] `advanced/lru_cache` — `lru_cache.py`

每子目录另有 `notes.md`；运行示例：`python <脚本名>.py`。

## 子目录 ↔ 刷题索引（本仓库 `leetcode/`）

| 结构 / 专题 | 示例题 |
|-------------|--------|
| 链表 | [0206](../problems/leetcode/0206_reverse_linked_list/)、[0160](../problems/leetcode/0160_intersection_of_two_linked_lists/)、[138](../problems/leetcode/0138_copy_list_with_random_pointer/) |
| 栈 / 队列（题解侧） | [0084](../problems/leetcode/0084_largest_rectangle_in_histogram/) |
| 哈希 | [0001](../problems/leetcode/0001_two_sum/)、[380](../problems/leetcode/0380_insert_delete_getrandom_o1/) |
| 堆（设计题） | [355](../problems/leetcode/0355_design_twitter/) |
| 堆 | [0215](../problems/leetcode/0215_kth_largest_element_in_an_array/) |
| 二叉树遍历 | [0104](../problems/leetcode/0104_maximum_depth_of_binary_tree/)（见 `tree/binary_tree`） |
| BST | [0098](../problems/leetcode/0098_validate_binary_search_tree/) |
| Trie | [208](../problems/leetcode/0208_implement_trie/) |
| 线段树 / 树状数组 | [307](../problems/leetcode/0307_range_sum_query_mutable/)（单点改 + 区间和；题解用 BIT，可换线段树） |
| LRU | [0146](../problems/leetcode/0146_lru_cache/) |
| 并查集 | [0200](../problems/leetcode/0200_number_of_islands/)（连通块） |

算法范式侧索引见 [`algorithms/notes.md`](../algorithms/notes.md)。
