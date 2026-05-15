"""二叉树：四种遍历（递归 + 迭代）。"""

from __future__ import annotations
from collections import deque


class TreeNode:
    __slots__ = ("val", "left", "right")

    def __init__(self, val: int, left: TreeNode | None = None, right: TreeNode | None = None) -> None:
        self.val = val
        self.left = left
        self.right = right


def preorder_recursive(root: TreeNode | None) -> list[int]:
    out: list[int] = []

    def dfs(n: TreeNode | None) -> None:
        if n is None:
            return
        out.append(n.val)
        dfs(n.left)
        dfs(n.right)

    dfs(root)
    return out


def inorder_iterative(root: TreeNode | None) -> list[int]:
    out: list[int] = []
    st: list[TreeNode] = []
    cur: TreeNode | None = root
    while st or cur is not None:
        while cur is not None:
            st.append(cur)
            cur = cur.left
        cur = st.pop()
        out.append(cur.val)
        cur = cur.right
    return out


def postorder_recursive(root: TreeNode | None) -> list[int]:
    out: list[int] = []

    def dfs(n: TreeNode | None) -> None:
        if n is None:
            return
        dfs(n.left)
        dfs(n.right)
        out.append(n.val)

    dfs(root)
    return out


def level_order(root: TreeNode | None) -> list[list[int]]:
    if root is None:
        return []
    res: list[list[int]] = []
    q: deque[TreeNode] = deque([root])
    while q:
        level: list[int] = []
        for _ in range(len(q)):
            n = q.popleft()
            level.append(n.val)
            if n.left is not None:
                q.append(n.left)
            if n.right is not None:
                q.append(n.right)
        res.append(level)
    return res


if __name__ == "__main__":
    #       1
    #      / \
    #     2   3
    #    /
    #   4
    root = TreeNode(1, TreeNode(2, TreeNode(4)), TreeNode(3))
    assert preorder_recursive(root) == [1, 2, 4, 3]
    assert inorder_iterative(root) == [4, 2, 1, 3]
    assert postorder_recursive(root) == [4, 2, 3, 1]
    assert level_order(root) == [[1], [2, 3], [4]]
    assert level_order(None) == []
    assert preorder_recursive(None) == []
    print("BinaryTree OK")
