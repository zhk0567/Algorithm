"""树形 DP：二叉树打家劫舍。"""

from __future__ import annotations


class TreeNode:
    __slots__ = ("val", "left", "right")

    def __init__(self, val: int = 0, left: TreeNode | None = None, right: TreeNode | None = None) -> None:
        self.val = val
        self.left = left
        self.right = right


def rob_tree(root: TreeNode | None) -> int:
    """返回 (选根最大, 不选根最大) 对根而言。"""

    def dfs(n: TreeNode | None) -> tuple[int, int]:
        if n is None:
            return 0, 0
        l0, l1 = dfs(n.left)
        r0, r1 = dfs(n.right)
        take = n.val + l0 + r0
        skip = max(l0, l1) + max(r0, r1)
        return skip, take

    a, b = dfs(root)
    return max(a, b)


if __name__ == "__main__":
    #     3
    #    / \
    #   2   3
    #    \   \
    #     3   1
    r = TreeNode(3, TreeNode(2, None, TreeNode(3)), TreeNode(3, None, TreeNode(1)))
    assert rob_tree(r) == 7
    assert rob_tree(None) == 0
    print("tree_dp OK")
