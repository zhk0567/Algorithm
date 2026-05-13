"""LeetCode 98: Validate Binary Search Tree."""

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
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(node: Optional[TreeNode], lo: float, hi: float) -> bool:
            if node is None:
                return True
            if not (lo < node.val < hi):
                return False
            return dfs(node.left, lo, node.val) and dfs(node.right, node.val, hi)

        return dfs(root, -inf, inf)


if __name__ == "__main__":
    # [2,1,3]
    assert Solution().isValidBST(TreeNode(2, TreeNode(1), TreeNode(3)))
    # [5,1,4,null,null,3,6]
    bad = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    assert not Solution().isValidBST(bad)
    print("0098 OK")
