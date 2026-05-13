"""LeetCode 114: Flatten Binary Tree to Linked List."""

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
    def flatten(self, root: Optional[TreeNode]) -> None:
        cur = root
        while cur is not None:
            if cur.left is not None:
                rightmost = cur.left
                while rightmost.right is not None:
                    rightmost = rightmost.right
                rightmost.right = cur.right
                cur.right = cur.left
                cur.left = None
            cur = cur.right


def to_right_chain(root: Optional[TreeNode]) -> list[int]:
    out: list[int] = []
    while root is not None:
        assert root.left is None
        out.append(root.val)
        root = root.right
    return out


if __name__ == "__main__":
    root = TreeNode(
        1,
        TreeNode(2, TreeNode(3), TreeNode(4)),
        TreeNode(5, None, TreeNode(6)),
    )
    Solution().flatten(root)
    assert to_right_chain(root) == [1, 2, 3, 4, 5, 6]
    Solution().flatten(None)
    one = TreeNode(0)
    Solution().flatten(one)
    assert to_right_chain(one) == [0]
    print("0114 OK")
