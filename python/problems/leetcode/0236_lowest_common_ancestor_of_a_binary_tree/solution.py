"""LeetCode 236: Lowest Common Ancestor of a Binary Tree."""

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
    def lowestCommonAncestor(
        self,
        root: Optional[TreeNode],
        p: TreeNode,
        q: TreeNode,
    ) -> Optional[TreeNode]:
        if root is None or root is p or root is q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left is not None and right is not None:
            return root
        return left if left is not None else right


if __name__ == "__main__":
    # [3,5,1,6,2,0,8,null,null,7,4]
    n7 = TreeNode(7)
    n4 = TreeNode(4)
    n6 = TreeNode(6)
    n2 = TreeNode(2, n7, n4)
    n0 = TreeNode(0)
    n8 = TreeNode(8)
    n5 = TreeNode(5, n6, n2)
    n1 = TreeNode(1, n0, n8)
    root = TreeNode(3, n5, n1)
    assert Solution().lowestCommonAncestor(root, n5, n1) is root
    assert Solution().lowestCommonAncestor(root, n5, n4) is n5
    print("0236 OK")
