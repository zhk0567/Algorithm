"""定长环形缓冲区：队尾入、队头出，满/空抛 BufferError。"""

from __future__ import annotations

from typing import Generic, Optional, TypeVar

T = TypeVar("T")


class RingBuffer(Generic[T]):
    def __init__(self, capacity: int) -> None:
        if capacity < 1:
            raise ValueError("capacity must be >= 1")
        self._cap = capacity
        self._buf: list[Optional[T]] = [None] * capacity
        self._head = 0
        self._tail = 0
        self._size = 0

    def __len__(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._size == 0

    def is_full(self) -> bool:
        return self._size == self._cap

    def push(self, item: T) -> None:
        if self.is_full():
            raise BufferError("ring buffer full")
        self._buf[self._tail] = item
        self._tail = (self._tail + 1) % self._cap
        self._size += 1

    def pop(self) -> T:
        if self.is_empty():
            raise BufferError("ring buffer empty")
        item = self._buf[self._head]
        assert item is not None
        self._buf[self._head] = None
        self._head = (self._head + 1) % self._cap
        self._size -= 1
        return item


if __name__ == "__main__":
    rb: RingBuffer[int] = RingBuffer(3)
    rb.push(1)
    rb.push(2)
    assert rb.pop() == 1
    rb.push(3)
    rb.push(4)
    assert rb.pop() == 2
    assert rb.pop() == 3
    assert rb.pop() == 4
    assert rb.is_empty()
    try:
        rb.pop()
    except BufferError:
        pass
    else:
        raise AssertionError("expected BufferError")
    rb.push(10)
    assert rb.pop() == 10
    print("ring_buffer OK")
