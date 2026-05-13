"""LeetCode 94: Binary Tree Inorder Traversal."""

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
    def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
        res: list[int] = []
        stack: list[TreeNode] = []
        cur = root
        while cur is not None or stack:
            while cur is not None:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            res.append(cur.val)
            cur = cur.right
        return res


if __name__ == "__main__":
    root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
    assert Solution().inorderTraversal(root) == [1, 3, 2]
    assert Solution().inorderTraversal(None) == []
    assert Solution().inorderTraversal(TreeNode(1)) == [1]
    print("0094 OK")
