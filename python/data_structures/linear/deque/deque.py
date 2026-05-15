"""循环数组双端队列。"""

from __future__ import annotations


class CircularDeque:
    def __init__(self, cap: int = 8) -> None:
        if cap < 4:
            cap = 4
        self._cap = cap
        self._buf: list[object | None] = [None] * cap
        self._front = 0
        self._size = 0

    def __len__(self) -> int:
        return self._size

    def push_back(self, x: object) -> None:
        if self._size == self._cap:
            self._grow()
        idx = (self._front + self._size) % self._cap
        self._buf[idx] = x
        self._size += 1

    def push_front(self, x: object) -> None:
        if self._size == self._cap:
            self._grow()
        self._front = (self._front - 1 + self._cap) % self._cap
        self._buf[self._front] = x
        self._size += 1

    def pop_back(self) -> object:
        if self._size == 0:
            raise IndexError("pop_back empty")
        idx = (self._front + self._size - 1) % self._cap
        v = self._buf[idx]
        self._buf[idx] = None
        self._size -= 1
        return v  # type: ignore[return-value]

    def pop_front(self) -> object:
        if self._size == 0:
            raise IndexError("pop_front empty")
        v = self._buf[self._front]
        self._buf[self._front] = None
        self._front = (self._front + 1) % self._cap
        self._size -= 1
        return v  # type: ignore[return-value]

    def _grow(self) -> None:
        new_cap = self._cap * 2
        new_buf: list[object | None] = [None] * new_cap
        for i in range(self._size):
            new_buf[i] = self._buf[(self._front + i) % self._cap]
        self._buf = new_buf
        self._cap = new_cap
        self._front = 0


if __name__ == "__main__":
    d = CircularDeque(4)
    d.push_back(1)
    d.push_front(0)
    d.push_back(2)
    assert d.pop_front() == 0
    assert d.pop_back() == 2
    assert d.pop_front() == 1
    d2 = CircularDeque(4)
    try:
        d2.pop_front()
        raise AssertionError("expected IndexError")
    except IndexError:
        pass
    print("Deque OK")
