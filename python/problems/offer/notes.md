# 剑指 Offer（Python）

## 约定

- 与力扣**题意重合**的，只链 `../leetcode/<slug>/`，**不重复**建 `solution`。
- **剑指独占**（力扣无同题或仓库未收录）且确需代码时，再建 `offer_<编号>_<slug>/`（全库此类目录建议 ≤5）。
- 目录名也可写作 `offer_<力扣题号>_<slug>/`，在本表「力扣目录」列标明即可。

## 剑指 ↔ 本仓库 `leetcode/`（30 题索引）

| 剑指 | 题名（常见） | 力扣目录 / 说明 |
|------|--------------|-----------------|
| 3 | 数组中重复的数字 | [`0287_find_the_duplicate_number`](../leetcode/0287_find_the_duplicate_number/) |
| 5 | 替换空格 | **独占**（暂无同题 `leetcode/`，需要时再建 `offer_05_`） |
| 6、24 | 链表反转 / 从尾到头 | [`0206_reverse_linked_list`](../leetcode/0206_reverse_linked_list/) |
| 10-I | 斐波那契数列 | [`0070_climbing_stairs`](../leetcode/0070_climbing_stairs/) |
| 11 | 旋转数组的最小数字 | [`0033_search_in_rotated_sorted_array`](../leetcode/0033_search_in_rotated_sorted_array/) |
| 12 | 矩阵中的路径 | [`0062_unique_paths`](../leetcode/0062_unique_paths/) |
| 15 | 二进制中 1 的个数 | [`0136_single_number`](../leetcode/0136_single_number/)（位运算同类） |
| 19 | 正则表达式匹配 | [`0010_regular_expression_matching`](../leetcode/0010_regular_expression_matching/) |
| 22 | 链表中倒数第 k 个节点 | [`0019_remove_nth_node_from_end_of_list`](../leetcode/0019_remove_nth_node_from_end_of_list/) |
| 23 | 链表中环的入口节点 | [`0142_linked_list_cycle_ii`](../leetcode/0142_linked_list_cycle_ii/) |
| 25 | 合并两个排序的链表 | [`0021_merge_two_sorted_lists`](../leetcode/0021_merge_two_sorted_lists/) |
| 26 | 对称的二叉树 | [`0101_symmetric_tree`](../leetcode/0101_symmetric_tree/) |
| 27 | 二叉树的镜像 | [`0226_invert_binary_tree`](../leetcode/0226_invert_binary_tree/) |
| 28 | 从上到下打印二叉树 | [`0102_binary_tree_level_order_traversal`](../leetcode/0102_binary_tree_level_order_traversal/) |
| 31 | 栈的 min 函数 | [`0155_min_stack`](../leetcode/0155_min_stack/) |
| 34 | 两个链表的第一个公共节点 | [`0160_intersection_of_two_linked_lists`](../leetcode/0160_intersection_of_two_linked_lists/) |
| 35 | 复杂链表的复制 | [`0138_copy_list_with_random_pointer`](../leetcode/0138_copy_list_with_random_pointer/) |
| 39 | 数组中出现次数超过一半的数字 | [`0169_majority_element`](../leetcode/0169_majority_element/) |
| 42 | 连续子数组的最大和 | [`0053_maximum_subarray`](../leetcode/0053_maximum_subarray/) |
| 46 | 把数字翻译成字符串 | [`0091_decode_ways`](../leetcode/0091_decode_ways/) |
| 47 | 礼物的最大价值 | [`0064_minimum_path_sum`](../leetcode/0064_minimum_path_sum/) |
| 48 | 最长不含重复字符的子串 | [`0003_longest_substring_without_repeating_characters`](../leetcode/0003_longest_substring_without_repeating_characters/) |
| 51 | 数组中的逆序对 | **独占**（归并思想；暂无 `leetcode/` 目录） |
| 53 | 数字在排序数组中出现的次数 | [`0034_find_first_and_last_position_of_element_in_sorted_array`](../leetcode/0034_find_first_and_last_position_of_element_in_sorted_array/) |
| 55-I | 二叉树的深度 | [`0104_maximum_depth_of_binary_tree`](../leetcode/0104_maximum_depth_of_binary_tree/) |
| 63 | 股票的最大利润 | [`0121_best_time_to_buy_and_sell_stock`](../leetcode/0121_best_time_to_buy_and_sell_stock/) |
| 64 | 求 1+2+…+n | **独占**（递归/循环；非力扣原题归档） |
| 66 | 构建乘积数组 | [`0238_product_of_array_except_self`](../leetcode/0238_product_of_array_except_self/) |
| 67 | 把字符串转换成整数 | [`0008_string_to_integer_atoi`](../leetcode/0008_string_to_integer_atoi/) |
| 68-II | 二叉树的最近公共祖先 | [`0236_lowest_common_ancestor_of_a_binary_tree`](../leetcode/0236_lowest_common_ancestor_of_a_binary_tree/) |

**统计**：**30** 行索引，其中 **27** 行直链 `leetcode/`（90%），**3** 行剑指独占（未建 `offer_*` 目录）。

专题实现见 [`algorithms/`](../../algorithms/notes.md)、[`data_structures/`](../../data_structures/notes.md)；面试高频题单见 [`interview/top_frequent/notes.md`](../../interview/top_frequent/notes.md)。
