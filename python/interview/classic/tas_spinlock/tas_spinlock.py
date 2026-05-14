"""TAS 自旋锁（语义对照）：CPython 无 `atomic_flag`，用短临界区保护 0/1 标志 + 外层自旋。

与 C++ `std::atomic_flag::test_and_set` 同「占不到就转圈」的互斥语义，便于同一压力测对照；
生产环境请用 `threading.Lock` 或扩展模块提供的原子原语。
"""

from __future__ import annotations

import threading


class TASSpinLock:
    def __init__(self) -> None:
        self._mtx = threading.Lock()
        self._locked = False

    def acquire(self) -> None:
        while True:
            with self._mtx:
                if not self._locked:
                    self._locked = True
                    return

    def release(self) -> None:
        with self._mtx:
            self._locked = False


if __name__ == "__main__":
    lk = TASSpinLock()
    counter = [0]

    def worker() -> None:
        for _ in range(100):
            lk.acquire()
            try:
                counter[0] += 1
            finally:
                lk.release()

    ts = [threading.Thread(target=worker) for _ in range(10)]
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    assert counter[0] == 1000
    print("tas_spinlock OK")
