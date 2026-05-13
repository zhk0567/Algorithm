"""LeetCode 142: Linked List Cycle II."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head
        while fast is not None and fast.next is not None:
            slow = slow.next  # type: ignore[union-attr]
            fast = fast.next.next
            if slow is fast:
                p = head
                while p is not slow:
                    p = p.next  # type: ignore[union-attr]
                    slow = slow.next  # type: ignore[union-attr]
                return p
        return None


if __name__ == "__main__":
    n1, n2, n3, n4 = ListNode(3), ListNode(2), ListNode(0), ListNode(-4)
    n1.next, n2.next, n3.next, n4.next = n2, n3, n4, n2
    assert Solution().detectCycle(n1) is n2
    a = ListNode(1, ListNode(2))
    assert Solution().detectCycle(a) is None
    print("0142 OK")
