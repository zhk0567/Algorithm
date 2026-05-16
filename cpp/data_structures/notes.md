# 数据结构（C++）

> **全库覆盖盘点**（与 `algorithms/` 边界、缺口队列）：[算法覆盖总表](../../README.md#coverage)。

| 子目录 | 内容 |
|--------|------|
| `linear/` | 数组、链表、栈、队列、双端队列、哈希表 |
| `tree/` | 二叉树、BST、AVL、**红黑树**、Trie、线段树、树状数组、堆 |
| `graph/` | 邻接表、邻接矩阵、并查集 |
| `advanced/` | 跳表、布隆过滤器、LRU 等 |

## 已实现清单（第一阶段）

- [x] `linear/array` — `dynamic_array.cpp`
- [x] `linear/linked_list` — `linked_list.cpp`
- [x] `linear/stack` — `stack.cpp`
- [x] `linear/queue` — `queue.cpp`
- [x] `linear/deque` — `deque.cpp`
- [x] `linear/hash_table` — `hash_table.cpp`
- [x] `tree/binary_tree` — `binary_tree.cpp`
- [x] `tree/bst` — `bst.cpp`
- [x] `tree/avl` — `avl.cpp`
- [x] `tree/red_black_tree` — `red_black_tree.cpp`
- [x] `tree/trie` — `trie.cpp`
- [x] `tree/segment_tree` — `segment_tree.cpp`
- [x] `tree/fenwick_tree` — `fenwick_tree.cpp`
- [x] `tree/heap` — `heap.cpp`
- [x] `graph/adjacency_list` — `graph_list.cpp`
- [x] `graph/adjacency_matrix` — `graph_matrix.cpp`
- [x] `graph/disjoint_set` — `union_find.cpp`
- [x] `advanced/skip_list` — `skip_list.cpp`
- [x] `advanced/bloom_filter` — `bloom_filter.cpp`
- [x] `advanced/lru_cache` — `lru_cache.cpp`

各子目录 `notes.md` 含单文件编译命令（`g++` 或 MSVC `cl`，统一头见 [`cpp/include/alg_std.hpp`](../include/alg_std.hpp)）。

**通用编译**（在任意 `.cpp` 所在目录）：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe <文件名>.cpp
.\run.exe
```

若本机未安装 `g++`，可用 MSVC（见 [README](../../README.md#cpp-toolchain)）或在线 C++17 环境，编译时加 `-I cpp/include`。

## 子目录 ↔ 刷题索引（本仓库 `leetcode/`）

> 与 [Python 版](../../python/data_structures/notes.md) 同构。

| 结构 / 专题 | 示例题 |
|-------------|--------|
| 链表 | [0206](../problems/leetcode/0206_reverse_linked_list/)、[0160](../problems/leetcode/0160_intersection_of_two_linked_lists/)、[138](../problems/leetcode/0138_copy_list_with_random_pointer/) |
| 栈 / 队列（题解侧） | [0084](../problems/leetcode/0084_largest_rectangle_in_histogram/) |
| 哈希 | [0001](../problems/leetcode/0001_two_sum/)、[380](../problems/leetcode/0380_insert_delete_getrandom_o1/) |
| 堆（设计题） | [355](../problems/leetcode/0355_design_twitter/) |
| 堆 | [0215](../problems/leetcode/0215_kth_largest_element_in_an_array/) |
| 二叉树遍历 | [0104](../problems/leetcode/0104_maximum_depth_of_binary_tree/) |
| BST | [0098](../problems/leetcode/0098_validate_binary_search_tree/) |
| Trie | [208](../problems/leetcode/0208_implement_trie/) |
| 线段树 / 树状数组 | [307](../problems/leetcode/0307_range_sum_query_mutable/) |
| LRU | [0146](../problems/leetcode/0146_lru_cache/) |
| 并查集 | [0200](../problems/leetcode/0200_number_of_islands/) |

算法范式侧索引见 [`algorithms/notes.md`](../algorithms/notes.md)。
