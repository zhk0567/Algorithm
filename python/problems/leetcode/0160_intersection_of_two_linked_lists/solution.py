"""LeetCode 160: Intersection of Two Linked Lists."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def getIntersectionNode(
        self, headA: Optional[ListNode], headB: Optional[ListNode]
    ) -> Optional[ListNode]:
        a, b = headA, headB
        while a is not b:
            a = a.next if a is not None else headB
            b = b.next if b is not None else headA
        return a


if __name__ == "__main__":
    # A:    a1 -> a2 \
    #                 -> c1 -> c2 -> c3
    # B: b1 -> b2 -> b3 /
    c1 = ListNode(8)
    c2 = ListNode(4, c1)
    c3 = ListNode(5)
    c1.next = c2.next  # use c2->c3 chain: actually set explicitly below
    # Build properly:
    c1 = ListNode(8)
    c2 = ListNode(4)
    c3 = ListNode(5)
    c1.next = c2
    c2.next = c3
    a1 = ListNode(4)
    a2 = ListNode(1)
    a1.next = a2
    a2.next = c1
    b1 = ListNode(5)
    b2 = ListNode(6)
    b3 = ListNode(1)
    b1.next = b2
    b2.next = b3
    b3.next = c1
    assert Solution().getIntersectionNode(a1, b1) is c1

    # 无交点
    x1 = ListNode(1)
    x2 = ListNode(2)
    x1.next = x2
    y1 = ListNode(3)
    assert Solution().getIntersectionNode(x1, y1) is None
    print("0160 OK")
