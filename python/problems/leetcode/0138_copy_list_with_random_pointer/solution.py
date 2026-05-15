"""LeetCode 138: Copy List with Random Pointer."""

from __future__ import annotations


class Node:
    __slots__ = ("val", "next", "random")

    def __init__(
        self,
        val: int,
        next_: Node | None = None,
        random: Node | None = None,
    ) -> None:
        self.val = val
        self.next = next_
        self.random = random


class Solution:
    def copyRandomList(self, head: Node | None) -> Node | None:
        if head is None:
            return None
        mp: dict[Node, Node] = {}
        cur = head
        while cur:
            mp[cur] = Node(cur.val)
            cur = cur.next
        cur = head
        while cur:
            mp[cur].next = mp.get(cur.next)  # type: ignore[arg-type]
            mp[cur].random = mp.get(cur.random)  # type: ignore[arg-type]
            cur = cur.next
        return mp[head]


def build(vals: list[int], rnd: list[int | None]) -> Node | None:
    if not vals:
        return None
    nodes = [Node(v) for v in vals]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    for i, r in enumerate(rnd):
        nodes[i].random = nodes[r] if r is not None else None
    return nodes[0]


def vals_of(head: Node | None) -> list[int]:
    out: list[int] = []
    while head:
        out.append(head.val)
        head = head.next
    return out


def rnd_vals(head: Node | None) -> list[int | None]:
    out: list[int | None] = []
    while head:
        out.append(head.random.val if head.random else None)
        head = head.next
    return out


if __name__ == "__main__":
    a = build([7, 13, 11, 10, 1], [None, 0, 4, None, 0])
    b = Solution().copyRandomList(a)
    assert vals_of(b) == [7, 13, 11, 10, 1]
    assert rnd_vals(b) == [None, 7, 1, None, 7]
    assert Solution().copyRandomList(None) is None
    print("0138 OK")
