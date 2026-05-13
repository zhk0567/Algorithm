"""LeetCode 102: Binary Tree Level Order Traversal."""

from __future__ import annotations

from collections import deque
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
    def levelOrder(self, root: Optional[TreeNode]) -> list[list[int]]:
        res: list[list[int]] = []
        if root is None:
            return res
        q: deque[TreeNode] = deque([root])
        while q:
            level: list[int] = []
            for _ in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            res.append(level)
        return res


if __name__ == "__main__":
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    assert Solution().levelOrder(root) == [[3], [9, 20], [15, 7]]
    assert Solution().levelOrder(None) == []
    print("0102 OK")
