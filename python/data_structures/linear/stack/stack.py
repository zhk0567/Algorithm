"""数组栈、链表栈、最小栈。"""

from __future__ import annotations


class ArrayStack:
    def __init__(self) -> None:
        self._a: list[object] = []

    def push(self, x: object) -> None:
        self._a.append(x)

    def pop(self) -> object:
        if not self._a:
            raise IndexError("pop empty stack")
        return self._a.pop()

    def top(self) -> object:
        if not self._a:
            raise IndexError("top empty stack")
        return self._a[-1]

    def __len__(self) -> int:
        return len(self._a)


class ListNode:
    __slots__ = ("val", "next")

    def __init__(self, val: object, next_: ListNode | None = None) -> None:
        self.val = val
        self.next = next_


class LinkedStack:
    def __init__(self) -> None:
        self._head: ListNode | None = None

    def push(self, x: object) -> None:
        self._head = ListNode(x, self._head)

    def pop(self) -> object:
        if self._head is None:
            raise IndexError("pop empty stack")
        v = self._head.val
        self._head = self._head.next
        return v

    def top(self) -> object:
        if self._head is None:
            raise IndexError("top empty stack")
        return self._head.val


class MinStack:
    """主栈 + 辅助最小栈。"""

    def __init__(self) -> None:
        self._s: list[int] = []
        self._mins: list[int] = []

    def push(self, x: int) -> None:
        self._s.append(x)
        if not self._mins or x <= self._mins[-1]:
            self._mins.append(x)

    def pop(self) -> None:
        if not self._s:
            raise IndexError("pop empty")
        x = self._s.pop()
        if self._mins and x == self._mins[-1]:
            self._mins.pop()

    def top(self) -> int:
        if not self._s:
            raise IndexError("top empty")
        return self._s[-1]

    def get_min(self) -> int:
        if not self._mins:
            raise IndexError("get_min empty")
        return self._mins[-1]


if __name__ == "__main__":
    st = ArrayStack()
    st.push(1)
    st.push(2)
    assert st.pop() == 2 and st.top() == 1
    ls = LinkedStack()
    ls.push(3)
    assert ls.pop() == 3
    ms = MinStack()
    ms.push(2)
    ms.push(1)
    ms.push(1)
    assert ms.get_min() == 1
    ms.pop()
    assert ms.get_min() == 1
    ms.pop()
    assert ms.get_min() == 2
    print("Stack OK")
