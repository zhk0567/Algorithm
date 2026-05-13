"""LeetCode 148: Sort List."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        slow, fast = head, head.next
        while fast is not None and fast.next is not None:
            slow = slow.next  # type: ignore[assignment]
            fast = fast.next.next
        assert slow is not None
        mid = slow.next
        slow.next = None
        left = self.sortList(head)
        right = self.sortList(mid)
        return self._merge(left, right)

    @staticmethod
    def _merge(
        a: Optional[ListNode], b: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy
        while a is not None and b is not None:
            if a.val <= b.val:
                cur.next = a
                a = a.next
            else:
                cur.next = b
                b = b.next
            cur = cur.next
        cur.next = a if a is not None else b
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
    assert to_list(Solution().sortList(from_list([4, 2, 1, 3]))) == [1, 2, 3, 4]
    assert to_list(Solution().sortList(from_list([-1, 5, 3, 4, 0]))) == [
        -1, 0, 3, 4, 5,
    ]
    assert Solution().sortList(None) is None
    print("0148 OK")
