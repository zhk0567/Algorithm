# 算法与数据结构覆盖总表

> **用途**：对照 [仓库手册 · 学习路线](doc-handbook.md#study-roadmap) 盘点「已有双语文档 + 可运行入口」与「缺口」；**随补随改**本页，并在 [任务清单](doc-tasks.md) 中推进 P0。  
> **约定**：`✅` = `python/…` 与 `cpp/…` 均有入口源码 + 子目录 `notes.md`（或父级 `notes.md` 已覆盖）；`🔲` = 尚未建专题；`⚠` = 仅一侧或缺笔记（若出现请改状态）。

---

## 一、`algorithms/`（范式与专题）

| 专题 | 状态 | Python | C++ |
|------|------|----------|-----|
| 排序 | ✅ | [`sorting.py`](../python/algorithms/sorting/sorting.py) | [`sorting.cpp`](../cpp/algorithms/sorting/sorting.cpp) |
| 查找 / 二分 | ✅ | [`searching.py`](../python/algorithms/searching/searching.py) | [`searching.cpp`](../cpp/algorithms/searching/searching.cpp) |
| 递归 | ✅ | [`recursion.py`](../python/algorithms/recursion/recursion.py) | [`recursion.cpp`](../cpp/algorithms/recursion/recursion.cpp) |
| 分治 | ✅ | [`divide_and_conquer.py`](../python/algorithms/divide_and_conquer/divide_and_conquer.py) | [`divide_and_conquer.cpp`](../cpp/algorithms/divide_and_conquer/divide_and_conquer.cpp) |
| 贪心 | ✅ | [`greedy.py`](../python/algorithms/greedy/greedy.py) | [`greedy.cpp`](../cpp/algorithms/greedy/greedy.cpp) |
| 回溯 | ✅ | [`backtracking.py`](../python/algorithms/backtracking/backtracking.py) | [`backtracking.cpp`](../cpp/algorithms/backtracking/backtracking.cpp) |
| 双指针 | ✅ | [`two_pointers.py`](../python/algorithms/two_pointers/two_pointers.py) | [`two_pointers.cpp`](../cpp/algorithms/two_pointers/two_pointers.cpp) |
| 滑动窗口 | ✅ | [`sliding_window.py`](../python/algorithms/sliding_window/sliding_window.py) | [`sliding_window.cpp`](../cpp/algorithms/sliding_window/sliding_window.cpp) |
| 前缀和 / 差分 | ✅ | [`prefix_sum.py`](../python/algorithms/prefix_sum/prefix_sum.py) | [`prefix_sum.cpp`](../cpp/algorithms/prefix_sum/prefix_sum.cpp) |
| 位运算 | ✅ | [`bit_manipulation.py`](../python/algorithms/bit_manipulation/bit_manipulation.py) | [`bit_manipulation.cpp`](../cpp/algorithms/bit_manipulation/bit_manipulation.cpp) |
| 字符串（KMP 等） | ✅ | [`string_algorithms.py`](../python/algorithms/string/string_algorithms.py) | [`string_algorithms.cpp`](../cpp/algorithms/string/string_algorithms.cpp) |
| Z 函数 | ✅ | [`z_algorithm.py`](../python/algorithms/string/z_algorithm.py) | [`z_algorithm.cpp`](../cpp/algorithms/string/z_algorithm.cpp) |
| Manacher | ✅ | [`manacher.py`](../python/algorithms/string/manacher.py) | [`manacher.cpp`](../cpp/algorithms/string/manacher.cpp) |
| AC 自动机 | ✅ | [`ac_automaton.py`](../python/algorithms/string/ac_automaton.py) | [`ac_automaton.cpp`](../cpp/algorithms/string/ac_automaton.cpp) |
| 根号分块 | ✅ | [`sqrt_decomposition.py`](../python/algorithms/advanced/sqrt_decomposition.py) | [`sqrt_decomposition.cpp`](../cpp/algorithms/advanced/sqrt_decomposition.cpp) |
| 莫队 | ✅ | [`mo_algorithm.py`](../python/algorithms/advanced/mo_algorithm/mo_algorithm.py) | [`mo_algorithm.cpp`](../cpp/algorithms/advanced/mo_algorithm/mo_algorithm.cpp) |
| DP 线性 | ✅ | [`linear_dp.py`](../python/algorithms/dynamic_programming/linear/linear_dp.py) | [`linear_dp.cpp`](../cpp/algorithms/dynamic_programming/linear/linear_dp.cpp) |
| DP 区间 | ✅ | [`interval_dp.py`](../python/algorithms/dynamic_programming/interval/interval_dp.py) | [`interval_dp.cpp`](../cpp/algorithms/dynamic_programming/interval/interval_dp.cpp) |
| DP 树形 | ✅ | [`tree_dp.py`](../python/algorithms/dynamic_programming/tree/tree_dp.py) | [`tree_dp.cpp`](../cpp/algorithms/dynamic_programming/tree/tree_dp.cpp) |
| DP 数位 | ✅ | [`digit_dp.py`](../python/algorithms/dynamic_programming/digit/digit_dp.py) | [`digit_dp.cpp`](../cpp/algorithms/dynamic_programming/digit/digit_dp.cpp) |
| DP 状压 | ✅ | [`bitmask_dp.py`](../python/algorithms/dynamic_programming/bitmask/bitmask_dp.py) | [`bitmask_dp.cpp`](../cpp/algorithms/dynamic_programming/bitmask/bitmask_dp.cpp) |
| DP 背包 | ✅ | [`knapsack_dp.py`](../python/algorithms/dynamic_programming/knapsack/knapsack_dp.py) | [`knapsack_dp.cpp`](../cpp/algorithms/dynamic_programming/knapsack/knapsack_dp.cpp) |
| 图 DFS/BFS | ✅ | [`graph_traversal.py`](../python/algorithms/graph/traversal/graph_traversal.py) | [`graph_traversal.cpp`](../cpp/algorithms/graph/traversal/graph_traversal.cpp) |
| 最短路 Dijkstra | ✅ | [`dijkstra.py`](../python/algorithms/graph/shortest_path/dijkstra.py) | [`dijkstra.cpp`](../cpp/algorithms/graph/shortest_path/dijkstra.cpp) |
| 最短路 Bellman–Ford | ✅ | [`bellman_ford.py`](../python/algorithms/graph/shortest_path/bellman_ford.py) | [`bellman_ford.cpp`](../cpp/algorithms/graph/shortest_path/bellman_ford.cpp) |
| 最短路 Floyd–Warshall | ✅ | [`floyd_warshall.py`](../python/algorithms/graph/shortest_path/floyd_warshall.py) | [`floyd_warshall.cpp`](../cpp/algorithms/graph/shortest_path/floyd_warshall.cpp) |
| MST Kruskal | ✅ | [`kruskal.py`](../python/algorithms/graph/mst/kruskal.py) | [`kruskal.cpp`](../cpp/algorithms/graph/mst/kruskal.cpp) |
| MST Prim | ✅ | [`prim.py`](../python/algorithms/graph/mst/prim.py) | [`prim.cpp`](../cpp/algorithms/graph/mst/prim.cpp) |
| 拓扑 Kahn | ✅ | [`kahn.py`](../python/algorithms/graph/topological_sort/kahn.py) | [`kahn.cpp`](../cpp/algorithms/graph/topological_sort/kahn.cpp) |
| SCC Tarjan | ✅ | [`tarjan.py`](../python/algorithms/graph/scc/tarjan.py) | [`tarjan.cpp`](../cpp/algorithms/graph/scc/tarjan.cpp) |
| 最大流 Edmonds–Karp | ✅ | [`edmonds_karp.py`](../python/algorithms/graph/network_flow/edmonds_karp.py) | [`edmonds_karp.cpp`](../cpp/algorithms/graph/network_flow/edmonds_karp.cpp) |
| 二分图匹配（Kuhn / 匈牙利 KM） | ✅ | [`bipartite_matching.py`](../python/algorithms/graph/bipartite_matching/bipartite_matching.py) | [`bipartite_matching.cpp`](../cpp/algorithms/graph/bipartite_matching/bipartite_matching.cpp) |
| 树上 LCA（倍增） | ✅ | [`lca.py`](../python/algorithms/graph/lca/lca.py) | [`lca.cpp`](../cpp/algorithms/graph/lca/lca.cpp) |
| 数论 | ✅ | [`number_theory.py`](../python/algorithms/math/number_theory/number_theory.py) | [`number_theory.cpp`](../cpp/algorithms/math/number_theory/number_theory.cpp) |
| 快速幂 | ✅ | [`fast_power.py`](../python/algorithms/math/fast_power/fast_power.py) | [`fast_power.cpp`](../cpp/algorithms/math/fast_power/fast_power.cpp) |
| 扩展欧几里得 | ✅ | [`extended_gcd.py`](../python/algorithms/math/extended_gcd/extended_gcd.py) | [`extended_gcd.cpp`](../cpp/algorithms/math/extended_gcd/extended_gcd.cpp) |
| 组合数学 | ✅ | [`combinatorics.py`](../python/algorithms/math/combinatorics/combinatorics.py) | [`combinatorics.cpp`](../cpp/algorithms/math/combinatorics/combinatorics.cpp) |
| 矩阵 | ✅ | [`matrix.py`](../python/algorithms/math/matrix/matrix.py) | [`matrix.cpp`](../cpp/algorithms/math/matrix/matrix.cpp) |
| 计算几何 | ✅ | [`geometry.py`](../python/algorithms/math/geometry/geometry.py) | [`geometry.cpp`](../cpp/algorithms/math/geometry/geometry.cpp) |
| 概率 | ✅ | [`probability.py`](../python/algorithms/math/probability/probability.py) | [`probability.cpp`](../cpp/algorithms/math/probability/probability.cpp) |

**当前小计**：上表 **39** 行均为 ✅（与 [`python/algorithms/notes.md`](../python/algorithms/notes.md) 入口表一致）。

---

## 二、`data_structures/`（基础与进阶）

| 专题 | 状态 | Python | C++ |
|------|------|--------|-----|
| 动态数组 | ✅ | [`dynamic_array.py`](../python/data_structures/linear/array/dynamic_array.py) | [`dynamic_array.cpp`](../cpp/data_structures/linear/array/dynamic_array.cpp) |
| 链表 | ✅ | [`linked_list.py`](../python/data_structures/linear/linked_list/linked_list.py) | [`linked_list.cpp`](../cpp/data_structures/linear/linked_list/linked_list.cpp) |
| 栈 | ✅ | [`stack.py`](../python/data_structures/linear/stack/stack.py) | [`stack.cpp`](../cpp/data_structures/linear/stack/stack.cpp) |
| 队列 | ✅ | [`queue.py`](../python/data_structures/linear/queue/queue.py) | [`queue.cpp`](../cpp/data_structures/linear/queue/queue.cpp) |
| 双端队列 | ✅ | [`deque.py`](../python/data_structures/linear/deque/deque.py) | [`deque.cpp`](../cpp/data_structures/linear/deque/deque.cpp) |
| 哈希表 | ✅ | [`hash_table.py`](../python/data_structures/linear/hash_table/hash_table.py) | [`hash_table.cpp`](../cpp/data_structures/linear/hash_table/hash_table.cpp) |
| 二叉树 | ✅ | [`binary_tree.py`](../python/data_structures/tree/binary_tree/binary_tree.py) | [`binary_tree.cpp`](../cpp/data_structures/tree/binary_tree/binary_tree.cpp) |
| BST | ✅ | [`bst.py`](../python/data_structures/tree/bst/bst.py) | [`bst.cpp`](../cpp/data_structures/tree/bst/bst.cpp) |
| AVL | ✅ | [`avl.py`](../python/data_structures/tree/avl/avl.py) | [`avl.cpp`](../cpp/data_structures/tree/avl/avl.cpp) |
| 堆 | ✅ | [`heap.py`](../python/data_structures/tree/heap/heap.py) | [`heap.cpp`](../cpp/data_structures/tree/heap/heap.cpp) |
| 线段树（含懒标记） | ✅ | [`segment_tree.py`](../python/data_structures/tree/segment_tree/segment_tree.py) | [`segment_tree.cpp`](../cpp/data_structures/tree/segment_tree/segment_tree.cpp) |
| 树状数组 | ✅ | [`fenwick_tree.py`](../python/data_structures/tree/fenwick_tree/fenwick_tree.py) | [`fenwick_tree.cpp`](../cpp/data_structures/tree/fenwick_tree/fenwick_tree.cpp) |
| Trie | ✅ | [`trie.py`](../python/data_structures/tree/trie/trie.py) | [`trie.cpp`](../cpp/data_structures/tree/trie/trie.cpp) |
| 邻接表 | ✅ | [`graph_list.py`](../python/data_structures/graph/adjacency_list/graph_list.py) | [`graph_list.cpp`](../cpp/data_structures/graph/adjacency_list/graph_list.cpp) |
| 邻接矩阵 | ✅ | [`graph_matrix.py`](../python/data_structures/graph/adjacency_matrix/graph_matrix.py) | [`graph_matrix.cpp`](../cpp/data_structures/graph/adjacency_matrix/graph_matrix.cpp) |
| 并查集 | ✅ | [`union_find.py`](../python/data_structures/graph/disjoint_set/union_find.py) | [`union_find.cpp`](../cpp/data_structures/graph/disjoint_set/union_find.cpp) |
| 布隆过滤器 | ✅ | [`bloom_filter.py`](../python/data_structures/advanced/bloom_filter/bloom_filter.py) | [`bloom_filter.cpp`](../cpp/data_structures/advanced/bloom_filter/bloom_filter.cpp) |
| 跳表 | ✅ | [`skip_list.py`](../python/data_structures/advanced/skip_list/skip_list.py) | [`skip_list.cpp`](../cpp/data_structures/advanced/skip_list/skip_list.cpp) |
| 红黑树 | ✅ | [`red_black_tree.py`](../python/data_structures/tree/red_black_tree/red_black_tree.py) | [`red_black_tree.cpp`](../cpp/data_structures/tree/red_black_tree/red_black_tree.cpp) |
| LRU（结构级） | ✅ | [`lru_cache.py`](../python/data_structures/advanced/lru_cache/lru_cache.py) | [`lru_cache.cpp`](../cpp/data_structures/advanced/lru_cache/lru_cache.cpp) |

**当前小计**：上表 **20** 行均为 ✅。

**与 `algorithms/` 边界**：区间查询的「算法视角」（如莫队配合）在 `algorithms/advanced`；**可重复利用的索引结构**（线段树 / 树状数组）在 `data_structures/tree/`。

---

## 三、缺口与排队（待建专题，建议优先级自上而下）

*当前无 🔲 排队项；新增缺口请按上表格式追加本表。*

建完任一行后：在本表改 **✅**、补双链、更新 [`doc-handbook.md`](doc-handbook.md) 模板或复杂度表、并在 [`python/algorithms/notes.md`](../python/algorithms/notes.md) / [`cpp/algorithms/notes.md`](../cpp/algorithms/notes.md) 增加入口行。

---

## 四、刷题索引（与 `leetcode/` 对齐）

专题到题号的映射维护在（**仅链仓库内已有题解**）：

| 侧 | 文档 |
|----|------|
| 算法范式 | [`python/algorithms/notes.md`](../python/algorithms/notes.md) § 子目录 ↔ 刷题索引 |
| 数据结构 | [`python/data_structures/notes.md`](../python/data_structures/notes.md) § 子目录 ↔ 刷题索引 |
| C++ | [`cpp/algorithms/notes.md`](../cpp/algorithms/notes.md) 同构表 |

新专题落地后，请在上述 `notes.md` 增行，避免与 §一/§二 脱节。

---

*文档版本：与仓库当前树同步；后续只增改行与状态列。*
