"""手写动态数组（ArrayList 思想）：显式容量与扩容。"""

from __future__ import annotations


class DynamicArray:
    def __init__(self, initial_capacity: int = 4) -> None:
        if initial_capacity < 1:
            initial_capacity = 1
        self._capacity = initial_capacity
        self._size = 0
        self._data: list[object | None] = [None] * self._capacity

    def __len__(self) -> int:
        return self._size

    def capacity(self) -> int:
        return self._capacity

    def at(self, index: int) -> object:
        if index < 0 or index >= self._size:
            raise IndexError("index out of range")
        return self._data[index]  # type: ignore[return-value]

    def push_back(self, value: object) -> None:
        if self._size == self._capacity:
            self._resize(self._capacity * 2)
        self._data[self._size] = value
        self._size += 1

    def pop_back(self) -> object:
        if self._size == 0:
            raise IndexError("pop from empty array")
        self._size -= 1
        v = self._data[self._size]
        self._data[self._size] = None
        return v  # type: ignore[return-value]

    def insert(self, index: int, value: object) -> None:
        if index < 0 or index > self._size:
            raise IndexError("insert index out of range")
        if self._size == self._capacity:
            self._resize(self._capacity * 2)
        for i in range(self._size, index, -1):
            self._data[i] = self._data[i - 1]
        self._data[index] = value
        self._size += 1

    def erase(self, index: int) -> None:
        if index < 0 or index >= self._size:
            raise IndexError("erase index out of range")
        for i in range(index, self._size - 1):
            self._data[i] = self._data[i + 1]
        self._size -= 1
        self._data[self._size] = None

    def _resize(self, new_cap: int) -> None:
        new_data: list[object | None] = [None] * new_cap
        for i in range(self._size):
            new_data[i] = self._data[i]
        self._data = new_data
        self._capacity = new_cap


if __name__ == "__main__":
    a = DynamicArray(2)
    a.push_back(1)
    a.push_back(2)
    a.push_back(3)
    assert len(a) == 3 and a.at(2) == 3
    a.insert(1, 99)
    assert a.at(1) == 99
    a.erase(1)
    assert a.at(1) == 2
    assert a.pop_back() == 3
    assert len(a) == 2
    empty = DynamicArray()
    try:
        empty.pop_back()
        raise AssertionError("expected IndexError")
    except IndexError:
        pass
    try:
        empty.at(0)
        raise AssertionError("expected IndexError")
    except IndexError:
        pass
    print("DynamicArray OK", list(a.at(i) for i in range(len(a))))
