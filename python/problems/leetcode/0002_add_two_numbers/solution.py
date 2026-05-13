"""LeetCode 2: Add Two Numbers."""

from __future__ import annotations


class ListNode:
    __slots__ = ("val", "next")

    def __init__(self, val: int = 0, next_: ListNode | None = None) -> None:
        self.val = val
        self.next = next_


class Solution:
    def addTwoNumbers(self, l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
        dummy = ListNode(0)
        cur = dummy
        c = 0
        while l1 or l2 or c:
            s = c
            if l1:
                s += l1.val
                l1 = l1.next
            if l2:
                s += l2.val
                l2 = l2.next
            c, v = divmod(s, 10)
            cur.next = ListNode(v)
            cur = cur.next
        return dummy.next


def to_list(n: ListNode | None) -> list[int]:
    out: list[int] = []
    while n:
        out.append(n.val)
        n = n.next
    return out


def from_list(a: list[int]) -> ListNode | None:
    dummy = ListNode(0)
    cur = dummy
    for x in a:
        cur.next = ListNode(x)
        cur = cur.next
    return dummy.next


if __name__ == "__main__":
    l1 = from_list([2, 4, 3])
    l2 = from_list([5, 6, 4])
    ans = Solution().addTwoNumbers(l1, l2)
    assert to_list(ans) == [7, 0, 8]
    print("0002 OK")
