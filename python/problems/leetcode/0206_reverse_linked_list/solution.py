"""LeetCode 206: Reverse Linked List."""

from __future__ import annotations


class ListNode:
    __slots__ = ("val", "next")

    def __init__(self, val: int = 0, next_: ListNode | None = None) -> None:
        self.val = val
        self.next = next_


class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        prev: ListNode | None = None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        return prev


def to_list(n: ListNode | None) -> list[int]:
    out: list[int] = []
    while n:
        out.append(n.val)
        n = n.next
    return out


def from_list(a: list[int]) -> ListNode | None:
    d = ListNode(0)
    c = d
    for x in a:
        c.next = ListNode(x)
        c = c.next
    return d.next


if __name__ == "__main__":
    h = from_list([1, 2, 3, 4, 5])
    r = Solution().reverseList(h)
    assert to_list(r) == [5, 4, 3, 2, 1]
    print("0206 OK")
