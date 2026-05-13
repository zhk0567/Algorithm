"""LeetCode 226: Invert Binary Tree."""

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
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left, root.right = (
            self.invertTree(root.right),
            self.invertTree(root.left),
        )
        return root


def level(root: Optional[TreeNode]) -> list[Optional[int]]:
    out: list[Optional[int]] = []
    from collections import deque

    if root is None:
        return out
    q: deque[Optional[TreeNode]] = deque([root])
    while q:
        n = q.popleft()
        if n is None:
            out.append(None)
            continue
        out.append(n.val)
        q.append(n.left)
        q.append(n.right)
    while out and out[-1] is None:
        out.pop()
    return out


if __name__ == "__main__":
    root = TreeNode(
        4,
        TreeNode(2, TreeNode(1), TreeNode(3)),
        TreeNode(7, TreeNode(6), TreeNode(9)),
    )
    assert level(Solution().invertTree(root)) == [4, 7, 2, 9, 6, 3, 1]
    assert Solution().invertTree(None) is None
    print("0226 OK")
