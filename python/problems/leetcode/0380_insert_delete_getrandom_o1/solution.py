"""LeetCode 380: Insert Delete GetRandom O(1)."""

from __future__ import annotations

import random


class RandomizedSet:
    def __init__(self) -> None:
        self._idx: dict[int, int] = {}
        self._vals: list[int] = []

    def insert(self, val: int) -> bool:
        if val in self._idx:
            return False
        self._idx[val] = len(self._vals)
        self._vals.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self._idx:
            return False
        i = self._idx[val]
        last = self._vals[-1]
        self._vals[i] = last
        self._idx[last] = i
        self._vals.pop()
        del self._idx[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self._vals)


if __name__ == "__main__":
    s = RandomizedSet()
    assert s.insert(1)
    assert not s.insert(1)
    assert s.remove(2) is False
    assert s.insert(2)
    assert s.getRandom() in {1, 2}
    assert s.remove(1)
    assert s.getRandom() == 2
    print("0380 OK")
