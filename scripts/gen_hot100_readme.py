"""Generate hot100/README.md from Top 100 Liked order (负雪明烛 blog, 2021)."""

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
    7: "0007_reverse_integer",
    9: "0009_palindrome_number",
    11: "0011_container_with_most_water",
    15: "0015_three_sum",
    19: "0019_remove_nth_node_from_end_of_list",
    20: "0020_valid_parentheses",
    21: "0021_merge_two_sorted_lists",
    22: "0022_generate_parentheses",
    26: "0026_remove_duplicates_from_sorted_array",
    33: "0033_search_in_rotated_sorted_array",
    39: "0039_combination_sum",
    42: "0042_trapping_rain_water",
    46: "0046_permutations",
    53: "0053_maximum_subarray",
    70: "0070_climbing_stairs",
    72: "0072_edit_distance",
    84: "0084_largest_rectangle_in_histogram",
    101: "0101_symmetric_tree",
    121: "0121_best_time_to_buy_and_sell_stock",
    136: "0136_single_number",
    146: "0146_lru_cache",
    198: "0198_house_robber",
    206: "0206_reverse_linked_list",
    300: "0300_longest_increasing_subsequence",
}


def row(rank: int, pid: int, title: str) -> str:
    sub = IMPLEMENTED.get(pid)
    cell = f"`../leetcode/{sub}/`" if sub else "—"
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
            "新增题目：复制 [problem_template.md](../../../docs/problem_template.md) 为目录内 `README.md`，并添加 `solution.py` / `solution.cpp`，再将上表对应行改为 `../leetcode/.../` 链接。",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> None:
    assert len(HOT100) == 100
    text = build()
    repo_root = Path(__file__).resolve().parents[1]
    for lang in ("python", "cpp"):
        path = repo_root / lang / "problems" / "hot100" / "README.md"
        path.write_text(text, encoding="utf-8")
        print("wrote", path)


if __name__ == "__main__":
    main()
