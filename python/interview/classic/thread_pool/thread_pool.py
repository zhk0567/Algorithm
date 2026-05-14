"""简易线程池：`queue` + 固定数量 worker 线程；`shutdown` 先 `join` 再发哨兵。"""

from __future__ import annotations

import threading
from queue import Queue
from typing import Any, Callable, Optional, Tuple


class ThreadPool:
    def __init__(self, num_workers: int) -> None:
        if num_workers < 1:
            raise ValueError("num_workers must be >= 1")
        self._q: Queue[Optional[Tuple[Callable[..., Any], tuple[Any, ...], dict[str, Any]]]] = Queue()
        self._workers: list[threading.Thread] = []
        self._started = True
        for _ in range(num_workers):
            t = threading.Thread(target=self._loop, daemon=True)
            self._workers.append(t)
            t.start()

    def _loop(self) -> None:
        while True:
            item = self._q.get()
            try:
                if item is None:
                    return
                fn, args, kwargs = item
                fn(*args, **kwargs)
            finally:
                self._q.task_done()

    def submit(self, fn: Callable[..., Any], *args: Any, **kwargs: Any) -> None:
        if not self._started:
            raise RuntimeError("pool is shut down")
        self._q.put((fn, args, kwargs))

    def shutdown(self, wait: bool = True) -> None:
        if not self._started:
            return
        self._started = False
        if wait:
            self._q.join()
        for _ in self._workers:
            self._q.put(None)
        for t in self._workers:
            t.join()


if __name__ == "__main__":
    lock = threading.Lock()
    acc: list[int] = []

    def work(x: int) -> None:
        with lock:
            acc.append(x)

    pool = ThreadPool(4)
    for i in range(40):
        pool.submit(work, i)
    pool.shutdown(wait=True)
    assert len(acc) == 40
    assert set(acc) == set(range(40))
    print("thread_pool OK")
