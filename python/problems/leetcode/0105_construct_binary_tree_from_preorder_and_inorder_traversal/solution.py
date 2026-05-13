"""LeetCode 105: Construct Binary Tree from Preorder and Inorder Traversal."""

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
    def buildTree(
        self, preorder: list[int], inorder: list[int]
    ) -> Optional[TreeNode]:
        idx = {v: i for i, v in enumerate(inorder)}
        it = iter(preorder)

        def build(l: int, r: int) -> Optional[TreeNode]:
            if l > r:
                return None
            v = next(it)
            node = TreeNode(v)
            m = idx[v]
            node.left = build(l, m - 1)
            node.right = build(m + 1, r)
            return node

        return build(0, len(inorder) - 1)


def inorder_traverse(root: Optional[TreeNode]) -> list[int]:
    out: list[int] = []

    def dfs(n: Optional[TreeNode]) -> None:
        if n is None:
            return
        dfs(n.left)
        out.append(n.val)
        dfs(n.right)

    dfs(root)
    return out


if __name__ == "__main__":
    root = Solution().buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])
    assert inorder_traverse(root) == [9, 3, 15, 20, 7]
    assert Solution().buildTree([], []) is None
    print("0105 OK")
