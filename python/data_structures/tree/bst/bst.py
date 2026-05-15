"""二叉搜索树（无重复键）。"""

from __future__ import annotations


class BSTNode:
    __slots__ = ("key", "left", "right")

    def __init__(self, key: int) -> None:
        self.key = key
        self.left: BSTNode | None = None
        self.right: BSTNode | None = None


class BST:
    def __init__(self) -> None:
        self.root: BSTNode | None = None

    def search(self, key: int) -> bool:
        n = self.root
        while n is not None:
            if key == n.key:
                return True
            n = n.left if key < n.key else n.right
        return False

    def insert(self, key: int) -> None:
        if self.root is None:
            self.root = BSTNode(key)
            return
        n = self.root
        while True:
            if key == n.key:
                return
            if key < n.key:
                if n.left is None:
                    n.left = BSTNode(key)
                    return
                n = n.left
            else:
                if n.right is None:
                    n.right = BSTNode(key)
                    return
                n = n.right

    def _min_node(self, n: BSTNode) -> BSTNode:
        while n.left is not None:
            n = n.left
        return n

    def delete(self, key: int) -> None:
        self.root = self._delete(self.root, key)

    def _delete(self, n: BSTNode | None, key: int) -> BSTNode | None:
        if n is None:
            raise KeyError(key)
        if key < n.key:
            n.left = self._delete(n.left, key)
        elif key > n.key:
            n.right = self._delete(n.right, key)
        else:
            if n.left is None:
                return n.right
            if n.right is None:
                return n.left
            succ = self._min_node(n.right)
            n.key = succ.key
            n.right = self._delete(n.right, succ.key)
        return n

    def inorder(self) -> list[int]:
        out: list[int] = []

        def dfs(x: BSTNode | None) -> None:
            if x is None:
                return
            dfs(x.left)
            out.append(x.key)
            dfs(x.right)

        dfs(self.root)
        return out

    def kth(self, k: int) -> int:
        """k 从 1 开始。"""
        cnt = 0
        found: int | None = None

        def dfs(x: BSTNode | None) -> None:
            nonlocal cnt, found
            if x is None or found is not None:
                return
            dfs(x.left)
            cnt += 1
            if cnt == k:
                found = x.key
                return
            dfs(x.right)

        dfs(self.root)
        if found is None:
            raise IndexError("k out of range")
        return found


if __name__ == "__main__":
    t = BST()
    for x in [5, 3, 7, 2, 4, 6, 8]:
        t.insert(x)
    assert t.inorder() == [2, 3, 4, 5, 6, 7, 8]
    assert t.search(4) and not t.search(9)
    assert t.kth(1) == 2
    t.delete(3)
    assert t.inorder() == [2, 4, 5, 6, 7, 8]
    t.insert(5)
    assert t.inorder() == [2, 4, 5, 6, 7, 8]
    try:
        t.delete(99)
        raise AssertionError("expected KeyError")
    except KeyError:
        pass
    print("BST OK")
