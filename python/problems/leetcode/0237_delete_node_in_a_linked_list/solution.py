"""LeetCode 237: Delete Node in a Linked List."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def deleteNode(self, node: ListNode) -> None:
        assert node.next is not None
        node.val = node.next.val
        node.next = node.next.next


def to_list(h: Optional[ListNode]) -> list[int]:
    out: list[int] = []
    while h is not None:
        out.append(h.val)
        h = h.next
    return out


if __name__ == "__main__":
    a = ListNode(4)
    b = ListNode(5)
    c = ListNode(1)
    d = ListNode(9)
    a.next = b
    b.next = c
    c.next = d
    Solution().deleteNode(b)
    assert to_list(a) == [4, 1, 9]
    print("0237 OK")
