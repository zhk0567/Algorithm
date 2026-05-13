"""LeetCode 234: Palindrome Linked List."""

from __future__ import annotations

from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None) -> None:
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head is None or head.next is None:
            return True
        slow = fast = head
        while fast is not None and fast.next is not None:
            slow = slow.next  # type: ignore[assignment]
            fast = fast.next.next
        prev: Optional[ListNode] = None
        cur: Optional[ListNode] = slow
        while cur is not None:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        a: Optional[ListNode] = head
        b: Optional[ListNode] = prev
        while b is not None:
            assert a is not None
            if a.val != b.val:
                return False
            a = a.next
            b = b.next
        return True


def from_list(vs: list[int]) -> Optional[ListNode]:
    dummy = ListNode()
    cur = dummy
    for v in vs:
        cur.next = ListNode(v)
        cur = cur.next
    return dummy.next


if __name__ == "__main__":
    assert Solution().isPalindrome(from_list([1, 2, 2, 1]))
    assert not Solution().isPalindrome(from_list([1, 2]))
    assert Solution().isPalindrome(from_list([1]))
    print("0234 OK")
