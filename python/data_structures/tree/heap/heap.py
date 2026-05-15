"""手写小根堆（数组存储）。"""

from __future__ import annotations


class MinHeap:
    def __init__(self) -> None:
        self._a: list[int] = []

    def __len__(self) -> int:
        return len(self._a)

    def push(self, x: int) -> None:
        self._a.append(x)
        self._sift_up(len(self._a) - 1)

    def pop(self) -> int:
        if not self._a:
            raise IndexError("pop empty heap")
        if len(self._a) == 1:
            return self._a.pop()
        root = self._a[0]
        self._a[0] = self._a.pop()
        self._sift_down(0)
        return root

    def top(self) -> int:
        if not self._a:
            raise IndexError("top empty heap")
        return self._a[0]

    def _parent(self, i: int) -> int:
        return (i - 1) // 2

    def _sift_up(self, i: int) -> None:
        while i > 0:
            p = self._parent(i)
            if self._a[p] <= self._a[i]:
                break
            self._a[p], self._a[i] = self._a[i], self._a[p]
            i = p

    def _sift_down(self, i: int) -> None:
        n = len(self._a)
        while True:
            l = 2 * i + 1
            r = 2 * i + 2
            smallest = i
            if l < n and self._a[l] < self._a[smallest]:
                smallest = l
            if r < n and self._a[r] < self._a[smallest]:
                smallest = r
            if smallest == i:
                break
            self._a[i], self._a[smallest] = self._a[smallest], self._a[i]
            i = smallest


def heapify_inplace(arr: list[int]) -> MinHeap:
    """O(n) 建堆：把 arr 复制进堆并自底向上下沉。"""
    h = MinHeap()
    h._a = arr[:]
    for i in range(len(h._a) // 2 - 1, -1, -1):
        h._sift_down(i)
    return h


if __name__ == "__main__":
    h = MinHeap()
    for x in [5, 3, 7, 1]:
        h.push(x)
    assert h.top() == 1
    assert h.pop() == 1
    assert h.pop() == 3
    h2 = heapify_inplace([4, 10, 3, 5, 1])
    assert(h2.pop() == 1)
    h3 = MinHeap()
    try:
        h3.pop()
        raise AssertionError("expected IndexError")
    except IndexError:
        pass
    h3.push(42)
    assert h3.pop() == 42
    print("Heap OK")
