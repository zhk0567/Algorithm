# 算法分类（Python）

> **全库覆盖盘点**（含缺口队列）：[算法覆盖总表](../../README.md#coverage)。

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
| `graph/` | 遍历、最短路、MST、拓扑、强连通、网络流、二分图匹配、[树上 LCA](graph/lca/) |
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
| `string/` | `string_algorithms.py`、`z_algorithm.py`、`manacher.py`、`ac_automaton.py` |
| `advanced/` | `sqrt_decomposition.py`、`advanced/mo_algorithm/mo_algorithm.py` |
| `dynamic_programming/linear/` | `linear_dp.py` |
| `dynamic_programming/interval/` | `interval_dp.py` |
| `dynamic_programming/tree/` | `tree_dp.py` |
| `dynamic_programming/digit/` | `digit_dp.py` |
| `dynamic_programming/bitmask/` | `bitmask_dp.py` |
| `dynamic_programming/knapsack/` | `knapsack_dp.py` |
| `graph/traversal/` | `graph_traversal.py` |
| `graph/shortest_path/` | `dijkstra.py`、`bellman_ford.py`、`floyd_warshall.py` |
| `graph/mst/` | `kruskal.py`、`prim.py` |
| `graph/topological_sort/` | `kahn.py` |
| `graph/scc/` | `tarjan.py` |
| `graph/network_flow/` | `edmonds_karp.py` |
| `graph/bipartite_matching/` | `bipartite_matching.py` |
| `graph/lca/` | `lca.py` |
| `math/number_theory/` | `number_theory.py` |
| `math/fast_power/` | `fast_power.py` |
| `math/extended_gcd/` | `extended_gcd.py` |
| `math/combinatorics/` | `combinatorics.py` |
| `math/matrix/` | `matrix.py` |
| `math/geometry/` | `geometry.py` |
| `math/probability/` | `probability.py` |

## 子目录 ↔ 刷题索引（本仓库 `leetcode/`）

> 仅链到仓库内已有题解目录；随 `leetcode/` 扩容继续增行。数据结构侧见 [`data_structures/notes.md`](../data_structures/notes.md)。

| 专题 / 范式 | 示例题 |
|-------------|--------|
| 排序 | [0075](../problems/leetcode/0075_sort_colors/) |
| 二分 / 查找 | [0033](../problems/leetcode/0033_search_in_rotated_sorted_array/)、[0035](../problems/leetcode/0035_search_insert_position/) |
| 双指针 | [0011](../problems/leetcode/0011_container_with_most_water/)、[0015](../problems/leetcode/0015_three_sum/) |
| 滑动窗口 | [0003](../problems/leetcode/0003_longest_substring_without_repeating_characters/)、[0076](../problems/leetcode/0076_minimum_window_substring/)、[0239](../problems/leetcode/0239_sliding_window_maximum/)、[992](../problems/leetcode/0992_subarrays_with_k_different_integers/) |
| 前缀和 / 差分 | [0560](../problems/leetcode/0560_subarray_sum_equals_k/) |
| 贪心 | [0055](../problems/leetcode/0055_jump_game/) |
| 回溯 | [0022](../problems/leetcode/0022_generate_parentheses/)、[0046](../problems/leetcode/0046_permutations/)、[0051](../problems/leetcode/0051_n_queens/) |
| 位运算 | [0136](../problems/leetcode/0136_single_number/)、[0169](../problems/leetcode/0169_majority_element/) |
| 线性 DP | [0070](../problems/leetcode/0070_climbing_stairs/)、[0053](../problems/leetcode/0053_maximum_subarray/)、[0198](../problems/leetcode/0198_house_robber/) |
| 背包 DP | [0322](../problems/leetcode/0322_coin_change/) |
| 树形 DP | [0124](../problems/leetcode/0124_binary_tree_maximum_path_sum/) |
| 数位 DP | [600](../problems/leetcode/0600_non_negative_integers_without_consecutive_ones/) |
| 网络流 | 无 LeetCode Hot/高频标配题；见 [`graph/network_flow/edmonds_karp`](../algorithms/graph/network_flow/edmonds_karp.py) 入口自测 |
| 字符串 | [0028](../problems/leetcode/0028_implement_strstr/) |
| 单调栈（题解侧） | [0084](../problems/leetcode/0084_largest_rectangle_in_histogram/) |
| 图遍历 / 多源 BFS | [0200](../problems/leetcode/0200_number_of_islands/)、[0994](../problems/leetcode/0994_rotting_oranges/)、[542](../problems/leetcode/0542_01_matrix/) |
| 拓扑排序 | [0207](../problems/leetcode/0207_course_schedule/)、[210](../problems/leetcode/0210_course_schedule_ii/) |
| 最短路 | [743](../problems/leetcode/0743_network_delay_time/)、[787](../problems/leetcode/0787_cheapest_flights_within_k_stops/)、[127](../problems/leetcode/0127_word_ladder/) |
| 状压 / 全点访问 | [847](../problems/leetcode/0847_shortest_path_visiting_all_nodes/) |
| 强连通 / 桥 | [1192](../problems/leetcode/1192_critical_connections_in_the_network/) |
| 二分图 | [0785](../problems/leetcode/0785_is_graph_bipartite/) |
| MST / 并查集 | [1135](../problems/leetcode/1135_connecting_cities_with_minimum_cost/)、[1584](../problems/leetcode/1584_min_cost_to_connect_all_points/)、[0684](../problems/leetcode/0684_redundant_connection/) |
| 回文串 | [005](../problems/leetcode/0005_longest_palindromic_substring/)、[647](../problems/leetcode/0647_palindromic_substrings/) |
| 树上 LCA | [0236](../problems/leetcode/0236_lowest_common_ancestor_of_a_binary_tree/) |
| 区间结构（BIT / 线段树） | [307](../problems/leetcode/0307_range_sum_query_mutable/) |
| 莫队 | 无单一标配题号，见 [`advanced/mo_algorithm/notes.md`](advanced/mo_algorithm/notes.md) |

运行：`python <入口文件>`（在对应目录或带路径执行）。
