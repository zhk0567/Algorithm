"""手写 LFU Cache（O(1)）。"""

from __future__ import annotations

from typing import Optional


class _Node:
    __slots__ = ("key", "val", "freq", "prev", "next")

    def __init__(
        self,
        key: int = 0,
        val: int = 0,
        freq: int = 0,
        prev: Optional["_Node"] = None,
        next: Optional["_Node"] = None,
    ) -> None:
        self.key = key
        self.val = val
        self.freq = freq
        self.prev = prev
        self.next = next


class _DList:
    """带哨兵的双向链表：头侧最新、尾侧最久。"""

    def __init__(self) -> None:
        self.head = _Node()
        self.tail = _Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0

    def push_front(self, node: _Node) -> None:
        nxt = self.head.next
        assert nxt is not None
        node.prev = self.head
        node.next = nxt
        self.head.next = node
        nxt.prev = node
        self.size += 1

    def remove(self, node: _Node) -> None:
        p, n = node.prev, node.next
        assert p is not None and n is not None
        p.next = n
        n.prev = p
        node.prev = node.next = None
        self.size -= 1

    def pop_back(self) -> Optional[_Node]:
        if self.size == 0:
            return None
        node = self.tail.prev
        assert node is not None and node is not self.head
        self.remove(node)
        return node

    def empty(self) -> bool:
        return self.size == 0


class LFUCache:
    def __init__(self, capacity: int) -> None:
        self._cap = capacity
        self._kv: dict[int, _Node] = {}
        self._buckets: dict[int, _DList] = {}
        self._min_freq = 0

    def get(self, key: int) -> int:
        node = self._kv.get(key)
        if node is None:
            return -1
        self._bump(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if self._cap == 0:
            return
        node = self._kv.get(key)
        if node is not None:
            node.val = value
            self._bump(node)
            return
        if len(self._kv) >= self._cap:
            bucket = self._buckets[self._min_freq]
            evict = bucket.pop_back()
            assert evict is not None
            del self._kv[evict.key]
        node = _Node(key, value, 1)
        self._kv[key] = node
        self._buckets.setdefault(1, _DList()).push_front(node)
        self._min_freq = 1

    def _bump(self, node: _Node) -> None:
        old = node.freq
        bucket = self._buckets[old]
        bucket.remove(node)
        if bucket.empty() and self._min_freq == old:
            self._min_freq = old + 1
        node.freq = old + 1
        self._buckets.setdefault(node.freq, _DList()).push_front(node)


if __name__ == "__main__":
    c = LFUCache(2)
    c.put(1, 1)
    c.put(2, 2)
    assert c.get(1) == 1  # freq(1)=2, freq(2)=1
    c.put(3, 3)  # 淘汰 2
    assert c.get(2) == -1
    assert c.get(3) == 3  # freq(3)=2
    c.put(4, 4)  # freq(1)=2,freq(3)=2 -> 淘汰最久未用的 1
    assert c.get(1) == -1
    assert c.get(3) == 3
    assert c.get(4) == 4
    # 容量 0 -> 不存
    z = LFUCache(0)
    z.put(0, 0)
    assert z.get(0) == -1
    print("lfu_cache OK")
