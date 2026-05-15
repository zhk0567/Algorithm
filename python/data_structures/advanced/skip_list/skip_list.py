"""跳表：有序键（int），支持 search / insert / erase。"""

from __future__ import annotations
import random


MAX_LEVEL = 16
P = 0.5


class SLNode:
    __slots__ = ("key", "forward")

    def __init__(self, key: int, level: int) -> None:
        self.key = key
        self.forward: list[SLNode | None] = [None] * level


class SkipList:
    def __init__(self) -> None:
        self._neg_inf = -10**18
        self._head = SLNode(self._neg_inf, MAX_LEVEL)
        self._level = 1

    def _random_level(self) -> int:
        lvl = 1
        while random.random() < P and lvl < MAX_LEVEL:
            lvl += 1
        return lvl

    def search(self, key: int) -> bool:
        x = self._head
        for i in range(self._level - 1, -1, -1):
            while x.forward[i] is not None and x.forward[i].key < key:
                x = x.forward[i]  # type: ignore[union-attr]
        x = x.forward[0]
        return x is not None and x.key == key

    def insert(self, key: int) -> None:
        update: list[SLNode] = [self._head] * MAX_LEVEL
        x = self._head
        for i in range(self._level - 1, -1, -1):
            while x.forward[i] is not None and x.forward[i].key < key:
                x = x.forward[i]  # type: ignore[union-attr]
            update[i] = x
        x = x.forward[0]
        if x is not None and x.key == key:
            return
        lvl = self._random_level()
        if lvl > self._level:
            for i in range(self._level, lvl):
                update[i] = self._head
            self._level = lvl
        node = SLNode(key, lvl)
        for i in range(lvl):
            node.forward[i] = update[i].forward[i]
            update[i].forward[i] = node

    def erase(self, key: int) -> bool:
        update: list[SLNode] = [self._head] * MAX_LEVEL
        x = self._head
        for i in range(self._level - 1, -1, -1):
            while x.forward[i] is not None and x.forward[i].key < key:
                x = x.forward[i]  # type: ignore[union-attr]
            update[i] = x
        x = x.forward[0]
        if x is None or x.key != key:
            return False
        for i in range(self._level):
            if update[i].forward[i] is not x:
                continue
            update[i].forward[i] = x.forward[i]
        while self._level > 1 and self._head.forward[self._level - 1] is None:
            self._level -= 1
        return True


if __name__ == "__main__":
    random.seed(0)
    sl = SkipList()
    for k in [3, 6, 7, 9, 12]:
        sl.insert(k)
    assert sl.search(7) and not sl.search(8)
    assert sl.erase(6) and not sl.search(6)
    assert not sl.search(1)
    sl.insert(7)
    sl.insert(7)
    assert sl.erase(99) is False
    print("SkipList OK")
