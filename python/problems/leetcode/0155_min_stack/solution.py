"""LeetCode 155: Min Stack."""

from __future__ import annotations


class MinStack:
    def __init__(self) -> None:
        self._st: list[int] = []
        self._mn: list[int] = []

    def push(self, val: int) -> None:
        self._st.append(val)
        if not self._mn or val <= self._mn[-1]:
            self._mn.append(val)
        else:
            self._mn.append(self._mn[-1])

    def pop(self) -> None:
        self._st.pop()
        self._mn.pop()

    def top(self) -> int:
        return self._st[-1]

    def getMin(self) -> int:
        return self._mn[-1]


if __name__ == "__main__":
    s = MinStack()
    s.push(-2)
    s.push(0)
    s.push(-3)
    assert s.getMin() == -3
    s.pop()
    assert s.top() == 0
    assert s.getMin() == -2
    print("0155 OK")
