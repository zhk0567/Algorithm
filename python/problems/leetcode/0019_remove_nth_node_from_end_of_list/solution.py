"""LeetCode 19: Remove Nth Node From End of List."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(
        self, head: Optional[ListNode], n: int
    ) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        fast: Optional[ListNode] = dummy
        slow: ListNode = dummy
        for _ in range(n + 1):
            assert fast is not None
            fast = fast.next
        while fast is not None:
            fast = fast.next
            assert slow.next is not None
            slow = slow.next
        assert slow.next is not None
        slow.next = slow.next.next
        return dummy.next


def to_list(head: Optional[ListNode]) -> list[int]:
    out: list[int] = []
    while head is not None:
        out.append(head.val)
        head = head.next
    return out


def from_list(vs: list[int]) -> Optional[ListNode]:
    dummy = ListNode()
    cur = dummy
    for v in vs:
        cur.next = ListNode(v)
        cur = cur.next
    return dummy.next


if __name__ == "__main__":
    assert to_list(Solution().removeNthFromEnd(from_list([1, 2, 3, 4, 5]), 2)) == [
        1, 2, 3, 5,
    ]
    assert to_list(Solution().removeNthFromEnd(from_list([1]), 1)) == []
    assert to_list(Solution().removeNthFromEnd(from_list([1, 2]), 1)) == [1]
    print("0019 OK")
