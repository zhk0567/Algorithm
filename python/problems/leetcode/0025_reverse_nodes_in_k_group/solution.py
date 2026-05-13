"""LeetCode 25: Reverse Nodes in k-Group."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(
        self, head: Optional[ListNode], k: int
    ) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        pre: ListNode = dummy
        while True:
            tail: Optional[ListNode] = pre
            for _ in range(k):
                tail = tail.next if tail is not None else None
                if tail is None:
                    return dummy.next
            grp_head: Optional[ListNode] = pre.next
            next_grp: Optional[ListNode] = tail.next
            tail.next = None
            new_head, new_tail = self._reverse(grp_head)
            assert new_tail is not None
            pre.next = new_head
            new_tail.next = next_grp
            pre = new_tail

    @staticmethod
    def _reverse(
        head: Optional[ListNode],
    ) -> tuple[Optional[ListNode], Optional[ListNode]]:
        prev: Optional[ListNode] = None
        cur = head
        while cur is not None:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        return prev, head


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
    assert to_list(Solution().reverseKGroup(from_list([1, 2, 3, 4, 5]), 2)) == [
        2, 1, 4, 3, 5,
    ]
    assert to_list(Solution().reverseKGroup(from_list([1, 2, 3, 4, 5]), 3)) == [
        3, 2, 1, 4, 5,
    ]
    assert to_list(Solution().reverseKGroup(from_list([1, 2]), 1)) == [1, 2]
    print("0025 OK")
