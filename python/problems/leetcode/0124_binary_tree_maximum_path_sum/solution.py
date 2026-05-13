"""LeetCode 124: Binary Tree Maximum Path Sum."""

from __future__ import annotations

from math import inf
from typing import Optional


class TreeNode:
    def __init__(
        self,
        val: int = 0,
        left: Optional["TreeNode"] = None,
        right: Optional["TreeNode"] = None,
    ) -> None:
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        best = -inf

        def dfs(node: Optional[TreeNode]) -> int:
            nonlocal best
            if node is None:
                return 0
            l = max(dfs(node.left), 0)
            r = max(dfs(node.right), 0)
            best = max(best, node.val + l + r)
            return node.val + max(l, r)

        dfs(root)
        return int(best)


if __name__ == "__main__":
    assert Solution().maxPathSum(TreeNode(1, TreeNode(2), TreeNode(3))) == 6
    root = TreeNode(-10, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    assert Solution().maxPathSum(root) == 42
    assert Solution().maxPathSum(TreeNode(-3)) == -3
    print("0124 OK")
