"""AVL 树：插入与删除。"""

from __future__ import annotations


class AVLNode:
    __slots__ = ("key", "left", "right", "height")

    def __init__(self, key: int) -> None:
        self.key = key
        self.left: AVLNode | None = None
        self.right: AVLNode | None = None
        self.height = 1


def _h(n: AVLNode | None) -> int:
    return n.height if n is not None else 0


def _upd(n: AVLNode) -> None:
    n.height = 1 + max(_h(n.left), _h(n.right))


def _bf(n: AVLNode) -> int:
    return _h(n.left) - _h(n.right)


def _rotate_right(y: AVLNode) -> AVLNode:
    x = y.left
    assert x is not None
    t2 = x.right
    x.right = y
    y.left = t2
    _upd(y)
    _upd(x)
    return x


def _rotate_left(x: AVLNode) -> AVLNode:
    y = x.right
    assert y is not None
    t2 = y.left
    y.left = x
    x.right = t2
    _upd(x)
    _upd(y)
    return y


class AVLTree:
    def __init__(self) -> None:
        self.root: AVLNode | None = None

    def insert(self, key: int) -> None:
        self.root = self._insert(self.root, key)

    def _insert(self, n: AVLNode | None, key: int) -> AVLNode:
        if n is None:
            return AVLNode(key)
        if key < n.key:
            n.left = self._insert(n.left, key)
        elif key > n.key:
            n.right = self._insert(n.right, key)
        else:
            return n
        _upd(n)
        b = _bf(n)
        if b > 1 and n.left is not None and key < n.left.key:
            return _rotate_right(n)
        if b > 1 and n.left is not None and key > n.left.key:
            n.left = _rotate_left(n.left)
            return _rotate_right(n)
        if b < -1 and n.right is not None and key > n.right.key:
            return _rotate_left(n)
        if b < -1 and n.right is not None and key < n.right.key:
            n.right = _rotate_right(n.right)
            return _rotate_left(n)
        return n

    def delete(self, key: int) -> None:
        self.root = self._delete(self.root, key)

    def _min_node(self, n: AVLNode) -> AVLNode:
        while n.left is not None:
            n = n.left
        return n

    def _delete(self, n: AVLNode | None, key: int) -> AVLNode | None:
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
        return self._rebalance(n)

    def _rebalance(self, n: AVLNode | None) -> AVLNode | None:
        if n is None:
            return None
        _upd(n)
        b = _bf(n)
        if b > 1 and n.left is not None and _bf(n.left) >= 0:
            return _rotate_right(n)
        if b > 1 and n.left is not None and _bf(n.left) < 0:
            n.left = _rotate_left(n.left)
            return _rotate_right(n)
        if b < -1 and n.right is not None and _bf(n.right) <= 0:
            return _rotate_left(n)
        if b < -1 and n.right is not None and _bf(n.right) > 0:
            n.right = _rotate_right(n.right)
            return _rotate_left(n)
        return n

    def inorder(self) -> list[int]:
        out: list[int] = []

        def dfs(x: AVLNode | None) -> None:
            if x is None:
                return
            dfs(x.left)
            out.append(x.key)
            dfs(x.right)

        dfs(self.root)
        return out


if __name__ == "__main__":
    t = AVLTree()
    for x in [10, 20, 30, 40, 50, 25]:
        t.insert(x)
    t.delete(20)
    ord_ = t.inorder()
    assert ord_ == sorted(ord_)
    t.insert(10)
    assert t.inorder().count(10) == 1
    try:
        t.delete(999)
        raise AssertionError("expected KeyError")
    except KeyError:
        pass
    print("AVL OK", ord_)
