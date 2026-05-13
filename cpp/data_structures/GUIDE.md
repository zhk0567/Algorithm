# 数据结构（C++）

| 子目录 | 内容 |
|--------|------|
| `linear/` | 数组、链表、栈、队列、双端队列、哈希表 |
| `tree/` | 二叉树、BST、AVL、Trie、线段树、树状数组、堆 |
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

各子目录 `GUIDE.md` 含单文件编译命令（需 MinGW/GCC 的 `g++`，且支持 `bits/stdc++.h`）。

**通用编译**（在任意 `.cpp` 所在目录）：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe <文件名>.cpp
.\run.exe
```

若本机未安装 `g++`，可将代码复制到支持 `bits/stdc++.h` 的在线 GCC 环境验证。
