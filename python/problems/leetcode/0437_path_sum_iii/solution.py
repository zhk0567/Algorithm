"""LeetCode 437: Path Sum III."""

from __future__ import annotations

from collections import defaultdict
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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        prefix: dict[int, int] = defaultdict(int)
        prefix[0] = 1
        ans = 0

        def dfs(node: Optional[TreeNode], cur: int) -> None:
            nonlocal ans
            if node is None:
                return
            cur += node.val
            ans += prefix[cur - targetSum]
            prefix[cur] += 1
            dfs(node.left, cur)
            dfs(node.right, cur)
            prefix[cur] -= 1

        dfs(root, 0)
        return ans


if __name__ == "__main__":
    # [10,5,-3,3,2,null,11,3,-2,null,1]
    root = TreeNode(
        10,
        TreeNode(
            5,
            TreeNode(3, TreeNode(3), TreeNode(-2)),
            TreeNode(2, None, TreeNode(1)),
        ),
        TreeNode(-3, None, TreeNode(11)),
    )
    assert Solution().pathSum(root, 8) == 3
    assert Solution().pathSum(None, 0) == 0
    print("0437 OK")
