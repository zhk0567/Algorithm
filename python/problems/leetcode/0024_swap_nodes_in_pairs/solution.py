"""LeetCode 24: Swap Nodes in Pairs."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        pre = dummy
        while pre.next is not None and pre.next.next is not None:
            a = pre.next
            b = a.next
            a.next = b.next
            b.next = a
            pre.next = b
            pre = a
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
    assert to_list(Solution().swapPairs(from_list([1, 2, 3, 4]))) == [2, 1, 4, 3]
    assert to_list(Solution().swapPairs(from_list([1]))) == [1]
    assert Solution().swapPairs(None) is None
    print("0024 OK")
