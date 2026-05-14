"""有界 MPMC 队列（参考实现）：`deque` + `Condition`，与 C++ 无锁版同一压测形状。

CPython 无官方无锁 MPMC API；本文件用于 **正确性对拍**（总 push/pop 与累加和），非无锁语义。
"""

from __future__ import annotations

import threading
from collections import deque


class BoundedMpmcQueueRef:
    def __init__(self, capacity: int) -> None:
        self._cap = capacity
        self._buf: deque[int] = deque()
        self._lock = threading.Lock()
        self._not_empty = threading.Condition(self._lock)
        self._not_full = threading.Condition(self._lock)

    def push(self, v: int) -> None:
        with self._not_full:
            while len(self._buf) >= self._cap:
                self._not_full.wait()
            self._buf.append(v)
            self._not_empty.notify()

    def pop(self) -> int:
        with self._not_empty:
            while len(self._buf) == 0:
                self._not_empty.wait()
            v = self._buf.popleft()
            self._not_full.notify()
            return v


if __name__ == "__main__":
    k_cap = 1024
    k_each = 500
    q = BoundedMpmcQueueRef(k_cap)
    total = [0]
    lock_sum = threading.Lock()
    go = threading.Event()

    def producer() -> None:
        go.wait()
        for _ in range(k_each):
            q.push(1)

    def consumer() -> None:
        go.wait()
        s = 0
        for _ in range(k_each):
            s += q.pop()
        with lock_sum:
            total[0] += s

    ts = [threading.Thread(target=producer) for _ in range(8)]
    ts.extend(threading.Thread(target=consumer) for _ in range(8))
    for t in ts:
        t.start()
    go.set()
    for t in ts:
        t.join()
    assert total[0] == 8 * k_each
    print("mpmc_queue OK")
