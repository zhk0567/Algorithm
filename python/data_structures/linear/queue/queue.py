"""循环数组队列 + 双栈队列。"""

from __future__ import annotations


class CircularArrayQueue:
    def __init__(self, cap: int = 8) -> None:
        if cap < 2:
            cap = 2
        self._cap = cap
        self._buf: list[object | None] = [None] * cap
        self._front = 0
        self._size = 0

    def __len__(self) -> int:
        return self._size

    def enqueue(self, x: object) -> None:
        if self._size == self._cap - 1:  # 留一空槽区分满/空
            self._grow()
        rear = (self._front + self._size) % self._cap
        self._buf[rear] = x
        self._size += 1

    def dequeue(self) -> object:
        if self._size == 0:
            raise IndexError("dequeue empty")
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


class StackQueue:
    """双栈实现队列。"""

    def __init__(self) -> None:
        self._in: list[object] = []
        self._out: list[object] = []

    def enqueue(self, x: object) -> None:
        self._in.append(x)

    def dequeue(self) -> object:
        if not self._out:
            while self._in:
                self._out.append(self._in.pop())
        if not self._out:
            raise IndexError("dequeue empty")
        return self._out.pop()


if __name__ == "__main__":
    q = CircularArrayQueue(4)
    q.enqueue(1)
    q.enqueue(2)
    assert q.dequeue() == 1
    q.enqueue(3)
    assert q.dequeue() == 2
    sq = StackQueue()
    sq.enqueue("a")
    sq.enqueue("b")
    assert sq.dequeue() == "a"
    print("Queue OK")
