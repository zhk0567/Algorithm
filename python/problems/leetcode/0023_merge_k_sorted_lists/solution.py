"""LeetCode 23: Merge k Sorted Lists."""

from __future__ import annotations

import heapq
from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: list[Optional[ListNode]]) -> Optional[ListNode]:
        heap: list[tuple[int, int, ListNode]] = []
        for i, head in enumerate(lists):
            if head is not None:
                heapq.heappush(heap, (head.val, i, head))
        dummy = ListNode()
        cur = dummy
        counter = len(lists)
        while heap:
            _, _, node = heapq.heappop(heap)
            cur.next = node
            cur = node
            if node.next is not None:
                heapq.heappush(heap, (node.next.val, counter, node.next))
                counter += 1
        cur.next = None
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
    lists = [from_list([1, 4, 5]), from_list([1, 3, 4]), from_list([2, 6])]
    assert to_list(Solution().mergeKLists(lists)) == [1, 1, 2, 3, 4, 4, 5, 6]
    assert Solution().mergeKLists([]) is None
    assert to_list(Solution().mergeKLists([None, from_list([1])])) == [1]
    print("0023 OK")
