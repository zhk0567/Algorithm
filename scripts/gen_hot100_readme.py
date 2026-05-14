"""Generate hot100/notes.md from Top 100 Liked order (负雪明烛 blog, 2021)."""

from __future__ import annotations

from pathlib import Path

# (leetcode_id, English title) in like-rank order
HOT100: list[tuple[int, str]] = [
    (1, "Two Sum"),
    (2, "Add Two Numbers"),
    (3, "Longest Substring Without Repeating Characters"),
    (4, "Median of Two Sorted Arrays"),
    (5, "Longest Palindromic Substring"),
    (15, "3Sum"),
    (53, "Maximum Subarray"),
    (7, "Reverse Integer"),
    (11, "Container With Most Water"),
    (42, "Trapping Rain Water"),
    (20, "Valid Parentheses"),
    (10, "Regular Expression Matching"),
    (26, "Remove Duplicates from Sorted Array"),
    (136, "Single Number"),
    (22, "Generate Parentheses"),
    (206, "Reverse Linked List"),
    (21, "Merge Two Sorted Lists"),
    (70, "Climbing Stairs"),
    (300, "Longest Increasing Subsequence"),
    (121, "Best Time to Buy and Sell Stock"),
    (72, "Edit Distance"),
    (14, "Longest Common Prefix"),
    (198, "House Robber"),
    (9, "Palindrome Number"),
    (146, "LRU Cache"),
    (19, "Remove Nth Node From End of List"),
    (33, "Search in Rotated Sorted Array"),
    (46, "Permutations"),
    (101, "Symmetric Tree"),
    (84, "Largest Rectangle in Histogram"),
    (39, "Combination Sum"),
    (13, "Roman to Integer"),
    (23, "Merge k Sorted Lists"),
    (17, "Letter Combinations of a Phone Number"),
    (322, "Coin Change"),
    (32, "Longest Valid Parentheses"),
    (287, "Find the Duplicate Number"),
    (122, "Best Time to Buy and Sell Stock II"),
    (160, "Intersection of Two Linked Lists"),
    (55, "Jump Game"),
    (76, "Minimum Window Substring"),
    (200, "Number of Islands"),
    (78, "Subsets"),
    (31, "Next Permutation"),
    (96, "Unique Binary Search Trees"),
    (148, "Sort List"),
    (236, "Lowest Common Ancestor of a Binary Tree"),
    (25, "Reverse Nodes in k-Group"),
    (6, "ZigZag Conversion"),
    (152, "Maximum Product Subarray"),
    (215, "Kth Largest Element in an Array"),
    (8, "String to Integer (atoi)"),
    (41, "First Missing Positive"),
    (283, "Move Zeroes"),
    (141, "Linked List Cycle"),
    (98, "Validate Binary Search Tree"),
    (124, "Binary Tree Maximum Path Sum"),
    (105, "Construct Binary Tree from Preorder and Inorder Traversal"),
    (34, "Find First and Last Position of Element in Sorted Array"),
    (239, "Sliding Window Maximum"),
    (142, "Linked List Cycle II"),
    (139, "Word Break"),
    (45, "Jump Game II"),
    (169, "Majority Element"),
    (234, "Palindrome Linked List"),
    (62, "Unique Paths"),
    (189, "Rotate Array"),
    (94, "Binary Tree Inorder Traversal"),
    (56, "Merge Intervals"),
    (88, "Merge Sorted Array"),
    (560, "Subarray Sum Equals K"),
    (279, "Perfect Squares"),
    (35, "Search Insert Position"),
    (24, "Swap Nodes in Pairs"),
    (85, "Maximal Rectangle"),
    (28, "Implement strStr()"),
    (92, "Reverse Linked List II"),
    (155, "Min Stack"),
    (79, "Word Search"),
    (27, "Remove Element"),
    (51, "N-Queens"),
    (75, "Sort Colors"),
    (102, "Binary Tree Level Order Traversal"),
    (48, "Rotate Image"),
    (95, "Unique Binary Search Trees II"),
    (64, "Minimum Path Sum"),
    (406, "Queue Reconstruction by Height"),
    (226, "Invert Binary Tree"),
    (437, "Path Sum III"),
    (104, "Maximum Depth of Binary Tree"),
    (237, "Delete Node in a Linked List"),
    (337, "House Robber III"),
    (18, "4Sum"),
    (91, "Decode Ways"),
    (207, "Course Schedule"),
    (37, "Sudoku Solver"),
    (175, "Combine Two Tables"),
    (416, "Partition Equal Subset Sum"),
    (238, "Product of Array Except Self"),
    (114, "Flatten Binary Tree to Linked List"),
]

# Explicit folder names (4-digit + snake_case) for implemented problems
IMPLEMENTED: dict[int, str] = {
    1: "0001_two_sum",
    2: "0002_add_two_numbers",
    3: "0003_longest_substring_without_repeating_characters",
    4: "0004_median_of_two_sorted_arrays",
    5: "0005_longest_palindromic_substring",
    6: "0006_zigzag_conversion",
    7: "0007_reverse_integer",
    8: "0008_string_to_integer_atoi",
    9: "0009_palindrome_number",
    10: "0010_regular_expression_matching",
    11: "0011_container_with_most_water",
    13: "0013_roman_to_integer",
    14: "0014_longest_common_prefix",
    15: "0015_three_sum",
    17: "0017_letter_combinations_of_a_phone_number",
    18: "0018_four_sum",
    19: "0019_remove_nth_node_from_end_of_list",
    20: "0020_valid_parentheses",
    21: "0021_merge_two_sorted_lists",
    22: "0022_generate_parentheses",
    23: "0023_merge_k_sorted_lists",
    24: "0024_swap_nodes_in_pairs",
    25: "0025_reverse_nodes_in_k_group",
    26: "0026_remove_duplicates_from_sorted_array",
    27: "0027_remove_element",
    28: "0028_implement_strstr",
    31: "0031_next_permutation",
    32: "0032_longest_valid_parentheses",
    33: "0033_search_in_rotated_sorted_array",
    34: "0034_find_first_and_last_position_of_element_in_sorted_array",
    35: "0035_search_insert_position",
    37: "0037_sudoku_solver",
    39: "0039_combination_sum",
    41: "0041_first_missing_positive",
    42: "0042_trapping_rain_water",
    45: "0045_jump_game_ii",
    46: "0046_permutations",
    48: "0048_rotate_image",
    51: "0051_n_queens",
    53: "0053_maximum_subarray",
    55: "0055_jump_game",
    56: "0056_merge_intervals",
    62: "0062_unique_paths",
    64: "0064_minimum_path_sum",
    70: "0070_climbing_stairs",
    72: "0072_edit_distance",
    75: "0075_sort_colors",
    76: "0076_minimum_window_substring",
    78: "0078_subsets",
    79: "0079_word_search",
    84: "0084_largest_rectangle_in_histogram",
    85: "0085_maximal_rectangle",
    88: "0088_merge_sorted_array",
    91: "0091_decode_ways",
    92: "0092_reverse_linked_list_ii",
    94: "0094_binary_tree_inorder_traversal",
    95: "0095_unique_binary_search_trees_ii",
    96: "0096_unique_binary_search_trees",
    98: "0098_validate_binary_search_tree",
    101: "0101_symmetric_tree",
    102: "0102_binary_tree_level_order_traversal",
    104: "0104_maximum_depth_of_binary_tree",
    105: "0105_construct_binary_tree_from_preorder_and_inorder_traversal",
    114: "0114_flatten_binary_tree_to_linked_list",
    121: "0121_best_time_to_buy_and_sell_stock",
    122: "0122_best_time_to_buy_and_sell_stock_ii",
    124: "0124_binary_tree_maximum_path_sum",
    136: "0136_single_number",
    139: "0139_word_break",
    141: "0141_linked_list_cycle",
    142: "0142_linked_list_cycle_ii",
    146: "0146_lru_cache",
    148: "0148_sort_list",
    152: "0152_maximum_product_subarray",
    155: "0155_min_stack",
    160: "0160_intersection_of_two_linked_lists",
    169: "0169_majority_element",
    175: "0175_combine_two_tables",
    189: "0189_rotate_array",
    198: "0198_house_robber",
    200: "0200_number_of_islands",
    206: "0206_reverse_linked_list",
    207: "0207_course_schedule",
    215: "0215_kth_largest_element_in_an_array",
    226: "0226_invert_binary_tree",
    234: "0234_palindrome_linked_list",
    236: "0236_lowest_common_ancestor_of_a_binary_tree",
    237: "0237_delete_node_in_a_linked_list",
    238: "0238_product_of_array_except_self",
    239: "0239_sliding_window_maximum",
    279: "0279_perfect_squares",
    283: "0283_move_zeroes",
    287: "0287_find_the_duplicate_number",
    300: "0300_longest_increasing_subsequence",
    322: "0322_coin_change",
    337: "0337_house_robber_iii",
    406: "0406_queue_reconstruction_by_height",
    416: "0416_partition_equal_subset_sum",
    437: "0437_path_sum_iii",
    560: "0560_subarray_sum_equals_k",
}

# Problems with SQL-only solutions (no Python/C++ binary check).
SQL_ONLY: set[int] = {175}


def row(rank: int, pid: int, title: str) -> str:
    sub = IMPLEMENTED.get(pid)
    if sub is None:
        cell = "—"
    elif pid in SQL_ONLY:
        cell = f"`../leetcode/{sub}/` (SQL only)"
    else:
        cell = f"`../leetcode/{sub}/`"
    return f"| {rank} | {pid} | {title} | {cell} |"


def build() -> str:
    lines = [
        "# LeetCode Hot 100（索引）",
        "",
        "本题集为 **索引**：具体实现放在 `../leetcode/<4位编号>_<snake_case>/` 中。",
        "",
        "题序按 **力扣中文版点赞 Top 100**（参考 [负雪明烛整理](https://www.cnblogs.com/fuxuemingzhu/p/15435728.html)，与题号数值顺序无关）。",
        "",
        "| 热题排名 | 题号 | 标题 | 代码目录 |",
        "|---|------|------|----------|",
    ]
    for i, (pid, title) in enumerate(HOT100, start=1):
        lines.append(row(i, pid, title))
    lines.extend(
        [
            "",
            "新增题目：将 [doc-handbook.md](../../../docs/doc-handbook.md#problem-notes-template) 中 **Problem notes template** 一节抄入本目录 `notes.md`，并添加 `solution.py` / `solution.cpp`，再将上表对应行改为 `../leetcode/.../` 链接。",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> None:
    assert len(HOT100) == 100
    text = build()
    repo_root = Path(__file__).resolve().parents[1]
    for lang in ("python", "cpp"):
        path = repo_root / lang / "problems" / "hot100" / "notes.md"
        path.write_text(text, encoding="utf-8")
        print("wrote", path)


if __name__ == "__main__":
    main()
