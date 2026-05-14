# 算法分类（C++）

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
| `advanced/` | 分块 [`sqrt_decomposition`](advanced/sqrt_decomposition.cpp)、[莫队](advanced/mo_algorithm/) |

## 已实现源码（与 Python 同构）

各子目录 `notes.md` 含 `g++` 编译命令；入口 `.cpp` 与 [Python 版 `notes.md`](../../python/algorithms/notes.md) 中文件名对应（如 `sorting/sorting.cpp`、`graph/lca/lca.cpp`）。

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

**莫队**见 [`advanced/mo_algorithm/notes.md`](advanced/mo_algorithm/notes.md)。
