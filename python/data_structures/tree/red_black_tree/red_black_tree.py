"""红黑树：插入 + 中序遍历（教学实现，含插入后 fixup）。"""

from __future__ import annotations

RED, BLACK = True, False


class RBNode:
    __slots__ = ("key", "color", "left", "right", "parent")

    def __init__(self, key: int) -> None:
        self.key = key
        self.color = RED
        self.left: RBNode | None = None
        self.right: RBNode | None = None
        self.parent: RBNode | None = None


class RedBlackTree:
    def __init__(self) -> None:
        self.root: RBNode | None = None

    def _left_rotate(self, x: RBNode) -> None:
        y = x.right
        assert y is not None
        x.right = y.left
        if y.left is not None:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x is x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def _right_rotate(self, y: RBNode) -> None:
        x = y.left
        assert x is not None
        y.left = x.right
        if x.right is not None:
            x.right.parent = y
        x.parent = y.parent
        if y.parent is None:
            self.root = x
        elif y is y.parent.right:
            y.parent.right = x
        else:
            y.parent.left = x
        x.right = y
        y.parent = x

    def _insert_fixup(self, z: RBNode) -> None:
        while z.parent is not None and z.parent.color == RED:
            gp = z.parent.parent
            assert gp is not None
            if z.parent is gp.left:
                y = gp.right
                if y is not None and y.color == RED:
                    z.parent.color = BLACK
                    y.color = BLACK
                    gp.color = RED
                    z = gp
                else:
                    if z is z.parent.right:
                        z = z.parent
                        self._left_rotate(z)
                    z.parent.color = BLACK
                    gp.color = RED
                    self._right_rotate(gp)
            else:
                y = gp.left
                if y is not None and y.color == RED:
                    z.parent.color = BLACK
                    y.color = BLACK
                    gp.color = RED
                    z = gp
                else:
                    if z is z.parent.left:
                        z = z.parent
                        self._right_rotate(z)
                    z.parent.color = BLACK
                    gp.color = RED
                    self._left_rotate(gp)
        if self.root is not None:
            self.root.color = BLACK

    def insert(self, key: int) -> None:
        z = RBNode(key)
        y: RBNode | None = None
        x = self.root
        while x is not None:
            y = x
            if key < x.key:
                x = x.left
            elif key > x.key:
                x = x.right
            else:
                return
        z.parent = y
        if y is None:
            self.root = z
        elif key < y.key:
            y.left = z
        else:
            y.right = z
        self._insert_fixup(z)

    def search(self, key: int) -> bool:
        x = self.root
        while x is not None:
            if key == x.key:
                return True
            x = x.left if key < x.key else x.right
        return False

    def inorder(self) -> list[int]:
        out: list[int] = []

        def dfs(n: RBNode | None) -> None:
            if n is None:
                return
            dfs(n.left)
            out.append(n.key)
            dfs(n.right)

        dfs(self.root)
        return out


def _check_rb(n: RBNode | None) -> int:
    """黑高一致；红结点子为黑。返回黑高。"""
    if n is None:
        return 1
    if n.color == RED:
        for ch in (n.left, n.right):
            if ch is not None and ch.color == RED:
                raise AssertionError("red-red child")
    lb = _check_rb(n.left)
    rb = _check_rb(n.right)
    if lb != rb:
        raise AssertionError("black height mismatch")
    return lb + (0 if n.color == RED else 1)


if __name__ == "__main__":
    t = RedBlackTree()
    keys = [10, 20, 30, 15, 25, 5, 1]
    for k in keys:
        t.insert(k)
    ord_ = t.inorder()
    assert ord_ == sorted(keys)
    assert t.search(25) and not t.search(99)
    if t.root is not None:
        assert t.root.color == BLACK
        _check_rb(t.root)
    t2 = RedBlackTree()
    assert not t2.search(1)
    t2.insert(5)
    assert t2.inorder() == [5] and t2.root is not None and t2.root.color == BLACK
    t2.insert(5)
    assert t2.inorder() == [5]
    print("red_black_tree OK", ord_)
