"""手写 LRU Cache：双向链表 + 哈希表。"""

from __future__ import annotations

from typing import Optional


class _Node:
    __slots__ = ("key", "val", "prev", "next")

    def __init__(
        self,
        key: int = 0,
        val: int = 0,
        prev: Optional["_Node"] = None,
        next: Optional["_Node"] = None,
    ) -> None:
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next


class LRUCache:
    def __init__(self, capacity: int) -> None:
        if capacity <= 0:
            raise ValueError("capacity must be positive")
        self._cap = capacity
        self._map: dict[int, _Node] = {}
        self._head = _Node()
        self._tail = _Node()
        self._head.next = self._tail
        self._tail.prev = self._head

    def __len__(self) -> int:
        return len(self._map)

    def get(self, key: int) -> int:
        node = self._map.get(key)
        if node is None:
            return -1
        self._move_to_front(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        node = self._map.get(key)
        if node is not None:
            node.val = value
            self._move_to_front(node)
            return
        node = _Node(key, value)
        self._map[key] = node
        self._add_to_front(node)
        if len(self._map) > self._cap:
            evict = self._tail.prev
            assert evict is not None and evict is not self._head
            self._remove(evict)
            del self._map[evict.key]

    def _add_to_front(self, node: _Node) -> None:
        nxt = self._head.next
        assert nxt is not None
        node.prev = self._head
        node.next = nxt
        self._head.next = node
        nxt.prev = node

    def _remove(self, node: _Node) -> None:
        p, n = node.prev, node.next
        assert p is not None and n is not None
        p.next = n
        n.prev = p
        node.prev = node.next = None

    def _move_to_front(self, node: _Node) -> None:
        self._remove(node)
        self._add_to_front(node)


if __name__ == "__main__":
    c = LRUCache(2)
    c.put(1, 1)
    c.put(2, 2)
    assert c.get(1) == 1
    c.put(3, 3)
    assert c.get(2) == -1
    c.put(4, 4)
    assert c.get(1) == -1
    assert c.get(3) == 3
    assert c.get(4) == 4
    c.put(4, 40)
    assert c.get(4) == 40
    assert len(c) == 2
    print("lru_cache OK")
