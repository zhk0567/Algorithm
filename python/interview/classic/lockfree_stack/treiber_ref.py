"""Treiber 栈「参考实现」：用互斥锁串行化，结构与无锁版一致，便于在纯 Python 里做多线程自测。"""

from __future__ import annotations

import threading
from dataclasses import dataclass
from typing import Optional


@dataclass
class _Node:
    val: int
    next: Optional["_Node"] = None


class TreiberStackRef:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self._head: Optional[_Node] = None

    def push(self, val: int) -> None:
        with self._lock:
            self._head = _Node(val, self._head)

    def try_pop(self) -> Optional[int]:
        with self._lock:
            if self._head is None:
                return None
            v = self._head.val
            self._head = self._head.next
            return v


if __name__ == "__main__":
    st = TreiberStackRef()
    barrier = threading.Barrier(8)

    def worker(i: int) -> None:
        barrier.wait()
        for j in range(50):
            st.push(i * 1000 + j)

    ts = [threading.Thread(target=worker, args=(i,)) for i in range(8)]
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    got = 0
    while st.try_pop() is not None:
        got += 1
    assert got == 8 * 50
    print("treiber_ref OK")
