"""手写计数信号量：mutex + Condition（与 threading.Semaphore 对照学习）。"""

from __future__ import annotations

import threading
import time
from typing import Optional


class Semaphore:
    def __init__(self, value: int) -> None:
        if value < 0:
            raise ValueError("value must be non-negative")
        self._cond = threading.Condition()
        self._count = value

    def acquire(self, blocking: bool = True, timeout: Optional[float] = None) -> bool:
        with self._cond:
            if not blocking:
                if self._count == 0:
                    return False
                self._count -= 1
                return True
            ok = self._cond.wait_for(lambda: self._count > 0, timeout=timeout)
            if not ok:
                return False
            self._count -= 1
            return True

    def release(self, n: int = 1) -> None:
        if n < 1:
            raise ValueError("n must be >= 1")
        with self._cond:
            self._count += n
            for _ in range(n):
                self._cond.notify()


if __name__ == "__main__":
    sem = Semaphore(2)
    gate = threading.Barrier(3)
    results: list[int] = []
    lock = threading.Lock()

    def worker(i: int) -> None:
        gate.wait()
        assert sem.acquire(timeout=2.0)
        with lock:
            results.append(i)
        time.sleep(0.05)
        sem.release()

    ts = [threading.Thread(target=worker, args=(i,)) for i in range(3)]
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    assert len(results) == 3
    sem2 = Semaphore(0)
    assert not sem2.acquire(blocking=False)
    sem2.release()
    assert sem2.acquire(blocking=False)
    print("semaphore OK")
