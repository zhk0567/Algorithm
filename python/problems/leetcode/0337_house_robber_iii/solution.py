"""LeetCode 337: House Robber III."""

from __future__ import annotations

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
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode]) -> tuple[int, int]:
            if node is None:
                return 0, 0
            ls, lk = dfs(node.left)
            rs, rk = dfs(node.right)
            steal = node.val + lk + rk
            skip = max(ls, lk) + max(rs, rk)
            return steal, skip

        return max(dfs(root))


if __name__ == "__main__":
    root = TreeNode(
        3,
        TreeNode(2, None, TreeNode(3)),
        TreeNode(3, None, TreeNode(1)),
    )
    assert Solution().rob(root) == 7
    root2 = TreeNode(
        3,
        TreeNode(4, TreeNode(1), TreeNode(3)),
        TreeNode(5, None, TreeNode(1)),
    )
    assert Solution().rob(root2) == 9
    assert Solution().rob(None) == 0
    print("0337 OK")
