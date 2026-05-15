"""LRU：哈希表 + 双向链表。"""

from __future__ import annotations


class DNode:
    __slots__ = ("key", "val", "prev", "next")

    def __init__(self, key: int = 0, val: int = 0) -> None:
        self.key = key
        self.val = val
        self.prev: DNode | None = None
        self.next: DNode | None = None


class LRUCache:
    def __init__(self, capacity: int) -> None:
        if capacity < 1:
            raise ValueError("capacity")
        self._cap = capacity
        self._map: dict[int, DNode] = {}
        self._head = DNode()
        self._tail = DNode()
        self._head.next = self._tail
        self._tail.prev = self._head

    def _remove(self, n: DNode) -> None:
        p, nx = n.prev, n.next
        assert p is not None and nx is not None
        p.next = nx
        nx.prev = p

    def _add_front(self, n: DNode) -> None:
        nx = self._head.next
        assert nx is not None
        self._head.next = n
        n.prev = self._head
        n.next = nx
        nx.prev = n

    def get(self, key: int) -> int:
        if key not in self._map:
            return -1
        n = self._map[key]
        self._remove(n)
        self._add_front(n)
        return n.val

    def put(self, key: int, value: int) -> None:
        if key in self._map:
            n = self._map[key]
            n.val = value
            self._remove(n)
            self._add_front(n)
            return
        if len(self._map) >= self._cap:
            lru = self._tail.prev
            assert lru is not None and lru is not self._head
            self._remove(lru)
            del self._map[lru.key]
        n = DNode(key, value)
        self._map[key] = n
        self._add_front(n)


if __name__ == "__main__":
    c = LRUCache(2)
    c.put(1, 1)
    c.put(2, 2)
    assert c.get(1) == 1
    c.put(3, 3)
    assert c.get(2) == -1
    c.put(4, 4)
    assert c.get(1) == -1 and c.get(3) == 3
    c1 = LRUCache(1)
    c1.put(1, 1)
    c1.put(2, 2)
    assert c1.get(1) == -1
    assert LRUCache(2).get(9) == -1
    try:
        LRUCache(0)
        raise AssertionError("expected ValueError")
    except ValueError:
        pass
    print("LRUCache OK")
