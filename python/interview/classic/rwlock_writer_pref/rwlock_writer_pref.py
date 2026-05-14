"""读写锁（写者优先）：写者持「读入口闸」阻塞新读者，再独占资源；避免读者饥饿写者。"""

from __future__ import annotations

import threading
import time
from contextlib import contextmanager
from typing import Generator


class WriterPreferRWLock:
    """多读者并发读；写者独占。新读者在写者等待进入时会被挡在闸门外。"""

    def __init__(self) -> None:
        self._read_gate = threading.Lock()
        self._guard = threading.Lock()
        self._resource = threading.Lock()
        self._readers = 0

    @contextmanager
    def read_lock(self) -> Generator[None, None, None]:
        self._read_gate.acquire()
        try:
            with self._guard:
                self._readers += 1
                if self._readers == 1:
                    self._resource.acquire()
        finally:
            self._read_gate.release()
        try:
            yield
        finally:
            with self._guard:
                self._readers -= 1
                if self._readers == 0:
                    self._resource.release()

    @contextmanager
    def write_lock(self) -> Generator[None, None, None]:
        self._read_gate.acquire()
        self._resource.acquire()
        try:
            yield
        finally:
            self._resource.release()
            self._read_gate.release()


if __name__ == "__main__":
    rw = WriterPreferRWLock()
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
    print("rwlock_writer_pref OK")
