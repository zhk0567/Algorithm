"""链地址法哈希表（int 键，任意值）。"""

from __future__ import annotations


class _Entry:
    __slots__ = ("key", "val", "next")

    def __init__(self, key: int, val: object, next_: _Entry | None = None) -> None:
        self.key = key
        self.val = val
        self.next = next_


class HashTableChaining:
    _LOAD_MAX = 0.75

    def __init__(self, initial_buckets: int = 8) -> None:
        if initial_buckets < 1:
            initial_buckets = 1
        self._n = 0
        self._m = initial_buckets
        self._buckets: list[_Entry | None] = [None] * self._m

    def __len__(self) -> int:
        return self._n

    @staticmethod
    def _h(key: int, m: int) -> int:
        return hash(key) % m

    def get(self, key: int) -> object:
        e = self._buckets[self._h(key, self._m)]
        while e is not None:
            if e.key == key:
                return e.val
            e = e.next
        raise KeyError(key)

    def insert(self, key: int, val: object) -> None:
        if (self._n + 1) > self._LOAD_MAX * self._m:
            self._rehash(self._m * 2)
        bi = self._h(key, self._m)
        e = self._buckets[bi]
        while e is not None:
            if e.key == key:
                e.val = val
                return
            e = e.next
        self._buckets[bi] = _Entry(key, val, self._buckets[bi])
        self._n += 1

    def erase(self, key: int) -> None:
        bi = self._h(key, self._m)
        head = self._buckets[bi]
        if head is None:
            raise KeyError(key)
        if head.key == key:
            self._buckets[bi] = head.next
            self._n -= 1
            return
        prev = head
        cur = head.next
        while cur is not None:
            if cur.key == key:
                prev.next = cur.next
                self._n -= 1
                return
            prev, cur = cur, cur.next
        raise KeyError(key)

    def _rehash(self, new_m: int) -> None:
        old = self._buckets
        self._m = max(1, new_m)
        self._n = 0
        self._buckets = [None] * self._m
        for head in old:
            e = head
            while e is not None:
                self.insert(e.key, e.val)
                e = e.next


if __name__ == "__main__":
    ht = HashTableChaining(4)
    ht.insert(1, "a")
    ht.insert(17, "b")  # may collide depending on m
    assert ht.get(1) == "a"
    ht.insert(1, "c")
    assert ht.get(1) == "c"
    ht.erase(1)
    try:
        ht.get(1)
    except KeyError:
        pass
    else:
        raise AssertionError
    print("HashTable OK", len(ht))
