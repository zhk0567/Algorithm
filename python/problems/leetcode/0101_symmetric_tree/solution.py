"""LeetCode 101: Symmetric Tree."""

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
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def mirror(a: Optional[TreeNode], b: Optional[TreeNode]) -> bool:
            if a is None or b is None:
                return a is None and b is None
            return (
                a.val == b.val
                and mirror(a.left, b.right)
                and mirror(a.right, b.left)
            )

        return root is None or mirror(root.left, root.right)


if __name__ == "__main__":
    # [1,2,2,3,4,4,3]
    root = TreeNode(
        1,
        TreeNode(2, TreeNode(3), TreeNode(4)),
        TreeNode(2, TreeNode(4), TreeNode(3)),
    )
    assert Solution().isSymmetric(root)
    # [1,2,2,null,3,null,3]
    bad = TreeNode(
        1, TreeNode(2, None, TreeNode(3)), TreeNode(2, None, TreeNode(3))
    )
    assert not Solution().isSymmetric(bad)
    print("0101 OK")
