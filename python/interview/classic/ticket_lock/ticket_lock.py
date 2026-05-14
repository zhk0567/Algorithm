"""Ticket Lock（公平锁）：取号 + 等待叫号，FIFO 顺序进入临界区。

实现为 `threading.Condition` + 整数票号（与纯自旋票号锁同语义，适合在纯 Python 中验证互斥与正确性）。
"""

from __future__ import annotations

import threading
from typing import Optional


class TicketLock:
    def __init__(self) -> None:
        self._mtx = threading.Lock()
        self._cv = threading.Condition(self._mtx)
        self._next_ticket = 0
        self._now_serving = 0

    def acquire(self, timeout: Optional[float] = None) -> bool:
        with self._cv:
            my = self._next_ticket
            self._next_ticket += 1
            return bool(self._cv.wait_for(lambda: self._now_serving == my, timeout=timeout))

    def release(self) -> None:
        with self._cv:
            self._now_serving += 1
            self._cv.notify_all()


if __name__ == "__main__":
    lk = TicketLock()
    counter = [0]

    def worker() -> None:
        for _ in range(100):
            assert lk.acquire(timeout=2.0)
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
    print("ticket_lock OK")
