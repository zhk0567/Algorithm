"""手写线程安全有界阻塞队列。"""

from __future__ import annotations

import threading
from collections import deque
from typing import Generic, Optional, TypeVar

T = TypeVar("T")


class Closed(Exception):
    pass


class BlockingQueue(Generic[T]):
    def __init__(self, capacity: int) -> None:
        if capacity <= 0:
            raise ValueError("capacity must be positive")
        self._cap = capacity
        self._buf: deque[T] = deque()
        self._lock = threading.Lock()
        self._not_full = threading.Condition(self._lock)
        self._not_empty = threading.Condition(self._lock)
        self._closed = False

    def put(self, item: T, timeout: Optional[float] = None) -> bool:
        with self._not_full:
            if not self._wait_for(self._not_full, lambda: len(self._buf) < self._cap, timeout):
                return False
            self._buf.append(item)
            self._not_empty.notify()
            return True

    def get(self, timeout: Optional[float] = None) -> T:
        with self._not_empty:
            if not self._wait_for(self._not_empty, lambda: len(self._buf) > 0, timeout):
                raise TimeoutError("get timed out")
            item = self._buf.popleft()
            self._not_full.notify()
            return item

    def close(self) -> None:
        with self._lock:
            self._closed = True
            self._not_full.notify_all()
            self._not_empty.notify_all()

    def qsize(self) -> int:
        with self._lock:
            return len(self._buf)

    def _wait_for(self, cond: threading.Condition, pred, timeout: Optional[float]) -> bool:
        ok = cond.wait_for(lambda: self._closed or pred(), timeout=timeout)
        if self._closed:
            raise Closed("queue closed")
        return ok


if __name__ == "__main__":
    q: BlockingQueue[int] = BlockingQueue(8)
    n_producer = 4
    per = 1000
    total = n_producer * per

    def producer(start: int) -> None:
        for i in range(per):
            q.put(start * per + i)

    consumed: list[int] = []
    consumed_lock = threading.Lock()

    stop = threading.Event()

    def consumer() -> None:
        while True:
            try:
                v = q.get(timeout=0.5)
            except TimeoutError:
                if stop.is_set() and q.qsize() == 0:
                    return
                continue
            with consumed_lock:
                consumed.append(v)

    ts = [threading.Thread(target=producer, args=(i,)) for i in range(n_producer)]
    cs = [threading.Thread(target=consumer) for _ in range(4)]
    for c in cs:
        c.start()
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    stop.set()
    for c in cs:
        c.join()

    assert len(consumed) == total
    assert len(set(consumed)) == total
    print("thread_safe_queue OK")
