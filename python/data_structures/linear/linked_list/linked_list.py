"""单链表与双链表（教学实现）。"""

from __future__ import annotations


class SNode:
    __slots__ = ("val", "next")

    def __init__(self, val: object, next_: SNode | None = None) -> None:
        self.val = val
        self.next = next_


class SinglyLinkedList:
    def __init__(self) -> None:
        self._dummy = SNode(0)
        self._size = 0

    def __len__(self) -> int:
        return self._size

    def append(self, val: object) -> None:
        cur = self._dummy
        while cur.next is not None:
            cur = cur.next
        cur.next = SNode(val)
        self._size += 1

    def prepend(self, val: object) -> None:
        self._dummy.next = SNode(val, self._dummy.next)
        self._size += 1

    def delete_first(self, val: object) -> bool:
        cur = self._dummy
        while cur.next is not None:
            if cur.next.val == val:
                cur.next = cur.next.next
                self._size -= 1
                return True
            cur = cur.next
        return False

    def reverse(self) -> None:
        prev: SNode | None = None
        cur = self._dummy.next
        self._dummy.next = None
        while cur is not None:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        self._dummy.next = prev

    def to_list(self) -> list[object]:
        out: list[object] = []
        cur = self._dummy.next
        while cur is not None:
            out.append(cur.val)
            cur = cur.next
        return out


class DNode:
    __slots__ = ("val", "prev", "next")

    def __init__(self, val: object) -> None:
        self.val = val
        self.prev: DNode | None = None
        self.next: DNode | None = None


class DoublyLinkedList:
    def __init__(self) -> None:
        self._head = DNode(0)
        self._tail = DNode(0)
        self._head.next = self._tail
        self._tail.prev = self._head
        self._size = 0

    def __len__(self) -> int:
        return self._size

    def append(self, val: object) -> None:
        node = DNode(val)
        p = self._tail.prev
        assert p is not None
        p.next = node
        node.prev = p
        node.next = self._tail
        self._tail.prev = node
        self._size += 1

    def prepend(self, val: object) -> None:
        node = DNode(val)
        n = self._head.next
        assert n is not None
        self._head.next = node
        node.prev = self._head
        node.next = n
        n.prev = node
        self._size += 1

    def remove_node(self, node: DNode) -> None:
        p, n = node.prev, node.next
        assert p is not None and n is not None
        p.next = n
        n.prev = p
        self._size -= 1

    def to_list(self) -> list[object]:
        out: list[object] = []
        cur = self._head.next
        while cur is not None and cur is not self._tail:
            out.append(cur.val)
            cur = cur.next
        return out


if __name__ == "__main__":
    s = SinglyLinkedList()
    s.append(1)
    s.append(2)
    s.prepend(0)
    assert s.to_list() == [0, 1, 2]
    s.reverse()
    assert s.to_list() == [2, 1, 0]
    d = DoublyLinkedList()
    d.append(1)
    d.append(2)
    d.prepend(0)
    assert d.to_list() == [0, 1, 2]
    mid = d._head.next
    assert mid is not None and mid.next is not None
    d.remove_node(mid.next)  # remove 1
    assert d.to_list() == [0, 2]
    print("LinkedList OK")
