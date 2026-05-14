# 算法分类（Python）

| 子目录 | 内容 |
|--------|------|
| `sorting/` | 冒泡、选择、插入、归并、快排、堆排、计数、基数、桶 |
| `searching/` | 线性查找、二分及变体 |
| `recursion/` | 递归基础 |
| `divide_and_conquer/` | 分治 |
| `greedy/` | 贪心 |
| `dynamic_programming/` | 线性 / 区间 / 树形 / 数位 / 状压 / 背包 |
| `backtracking/` | 回溯 |
| `two_pointers/` | 双指针 |
| `sliding_window/` | 滑动窗口 |
| `prefix_sum/` | 前缀和、差分 |
| `bit_manipulation/` | 位运算 |
| `graph/` | 遍历、最短路、MST、拓扑、强连通、网络流、[树上 LCA](graph/lca/) |
| `string/` | KMP 等 |
| `math/` | 数论、组合、矩阵、几何、概率 |
| `advanced/` | 分块 [`sqrt_decomposition`](advanced/sqrt_decomposition.py)、[莫队](advanced/mo_algorithm/) |

## 已实现脚本（第二阶段）

| 目录 | 入口文件 |
|------|------------|
| `sorting/` | `sorting.py` |
| `searching/` | `searching.py` |
| `recursion/` | `recursion.py` |
| `divide_and_conquer/` | `divide_and_conquer.py` |
| `greedy/` | `greedy.py` |
| `backtracking/` | `backtracking.py` |
| `two_pointers/` | `two_pointers.py` |
| `sliding_window/` | `sliding_window.py` |
| `prefix_sum/` | `prefix_sum.py` |
| `bit_manipulation/` | `bit_manipulation.py` |
| `string/` | `string_algorithms.py` |
| `advanced/` | `sqrt_decomposition.py`、`advanced/mo_algorithm/mo_algorithm.py` |
| `dynamic_programming/linear/` | `linear_dp.py` |
| `dynamic_programming/interval/` | `interval_dp.py` |
| `dynamic_programming/tree/` | `tree_dp.py` |
| `dynamic_programming/digit/` | `digit_dp.py` |
| `dynamic_programming/bitmask/` | `bitmask_dp.py` |
| `dynamic_programming/knapsack/` | `knapsack_dp.py` |
| `graph/traversal/` | `graph_traversal.py` |
| `graph/shortest_path/` | `dijkstra.py` |
| `graph/mst/` | `kruskal.py` |
| `graph/topological_sort/` | `kahn.py` |
| `graph/scc/` | `tarjan.py` |
| `graph/network_flow/` | `edmonds_karp.py` |
| `graph/lca/` | `lca.py` |
| `math/number_theory/` | `number_theory.py` |
| `math/combinatorics/` | `combinatorics.py` |
| `math/matrix/` | `matrix.py` |
| `math/geometry/` | `geometry.py` |
| `math/probability/` | `probability.py` |

## 子目录 ↔ 刷题索引（本仓库 `leetcode/`）

| 方向 | 示例题 |
|------|--------|
| 双指针 | [0011](../problems/leetcode/0011_container_with_most_water/)、[0015](../problems/leetcode/0015_three_sum/) |
| 滑动窗口 | [0003](../problems/leetcode/0003_longest_substring_without_repeating_characters/)、[0076](../problems/leetcode/0076_minimum_window_substring/) |
| 前缀和 / 差分 | [0560](../problems/leetcode/0560_subarray_sum_equals_k/) |
| 贪心 | [0055](../problems/leetcode/0055_jump_game/) |
| 图遍历 | [0200](../problems/leetcode/0200_number_of_islands/) |
| 拓扑 / 最短路 | [0207](../problems/leetcode/0207_course_schedule/) |
| 树上 LCA | [0236](../problems/leetcode/0236_lowest_common_ancestor_of_a_binary_tree/) |
| 线性 DP | [0070](../problems/leetcode/0070_climbing_stairs/)、[0053](../problems/leetcode/0053_maximum_subarray/) |
| 字符串 | [0028](../problems/leetcode/0028_implement_strstr/) |

随 `leetcode/` 扩容可继续加行；**莫队**无单一标配题号，见 [`advanced/mo_algorithm/notes.md`](advanced/mo_algorithm/notes.md)。

运行：`python <入口文件>`（在对应目录或带路径执行）。
