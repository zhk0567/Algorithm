"""读写锁（读者优先）：读者共享 `readers` 计数，首个读者持写互斥、末读者释放。"""

from __future__ import annotations

import threading
import time
from contextlib import contextmanager
from typing import Generator


class RWLock:
    """多读者并发读；写者独占。写者可能饥饿（读者优先）。"""

    def __init__(self) -> None:
        self._guard = threading.Lock()
        self._write = threading.Lock()
        self._readers = 0

    @contextmanager
    def read_lock(self) -> Generator[None, None, None]:
        with self._guard:
            self._readers += 1
            if self._readers == 1:
                self._write.acquire()
        try:
            yield
        finally:
            with self._guard:
                self._readers -= 1
                if self._readers == 0:
                    self._write.release()

    @contextmanager
    def write_lock(self) -> Generator[None, None, None]:
        self._write.acquire()
        try:
            yield
        finally:
            self._write.release()


if __name__ == "__main__":
    rw = RWLock()
    shared = {"x": 0}
    barrier = threading.Barrier(5)

    def reader() -> None:
        barrier.wait()
        for _ in range(20):
            with rw.read_lock():
                _ = shared["x"]
            time.sleep(0.001)

    def writer() -> None:
        barrier.wait()
        for _ in range(50):
            with rw.write_lock():
                shared["x"] = shared["x"] + 1
            time.sleep(0.0005)

    ts = [threading.Thread(target=reader) for _ in range(4)]
    ts.append(threading.Thread(target=writer))
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    assert shared["x"] == 50
    print("rwlock OK")
