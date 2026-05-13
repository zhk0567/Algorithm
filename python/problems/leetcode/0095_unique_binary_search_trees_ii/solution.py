"""LeetCode 95: Unique Binary Search Trees II."""

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
    def generateTrees(self, n: int) -> list[Optional[TreeNode]]:
        if n == 0:
            return []

        def build(l: int, r: int) -> list[Optional[TreeNode]]:
            if l > r:
                return [None]
            out: list[Optional[TreeNode]] = []
            for i in range(l, r + 1):
                for lt in build(l, i - 1):
                    for rt in build(i + 1, r):
                        out.append(TreeNode(i, lt, rt))
            return out

        return build(1, n)


def inorder(root: Optional[TreeNode]) -> list[int]:
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
    trees = Solution().generateTrees(3)
    assert len(trees) == 5
    for t in trees:
        seq = inorder(t)
        assert seq == sorted(seq)
    assert Solution().generateTrees(0) == []
    print("0095 OK")
