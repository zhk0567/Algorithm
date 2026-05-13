"""LeetCode 21: Merge Two Sorted Lists."""

from __future__ import annotations


class ListNode:
    __slots__ = ("val", "next")

    def __init__(self, val: int = 0, next_: ListNode | None = None) -> None:
        self.val = val
        self.next = next_


class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:
        dummy = ListNode(0)
        cur = dummy
        while list1 and list2:
            if list1.val <= list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next
        cur.next = list1 or list2
        return dummy.next


def to_list(n: ListNode | None) -> list[int]:
    out: list[int] = []
    while n:
        out.append(n.val)
        n = n.next
    return out


def from_list(a: list[int]) -> ListNode | None:
    d = ListNode(0)
    c = d
    for x in a:
        c.next = ListNode(x)
        c = c.next
    return d.next


if __name__ == "__main__":
    a = from_list([1, 2, 4])
    b = from_list([1, 3, 4])
    m = Solution().mergeTwoLists(a, b)
    assert to_list(m) == [1, 1, 2, 3, 4, 4]
    print("0021 OK")
