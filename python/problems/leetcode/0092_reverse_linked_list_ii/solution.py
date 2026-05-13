"""LeetCode 92: Reverse Linked List II."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], left: int, right: int
    ) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        pre = dummy
        for _ in range(left - 1):
            assert pre.next is not None
            pre = pre.next
        cur = pre.next
        for _ in range(right - left):
            assert cur is not None and cur.next is not None
            nxt = cur.next
            cur.next = nxt.next
            nxt.next = pre.next
            pre.next = nxt
        return dummy.next


def from_list(vs: list[int]) -> Optional[ListNode]:
    dummy = ListNode()
    cur = dummy
    for v in vs:
        cur.next = ListNode(v)
        cur = cur.next
    return dummy.next


def to_list(h: Optional[ListNode]) -> list[int]:
    out: list[int] = []
    while h is not None:
        out.append(h.val)
        h = h.next
    return out


if __name__ == "__main__":
    assert to_list(Solution().reverseBetween(from_list([1, 2, 3, 4, 5]), 2, 4)) == [
        1, 4, 3, 2, 5,
    ]
    assert to_list(Solution().reverseBetween(from_list([5]), 1, 1)) == [5]
    print("0092 OK")
