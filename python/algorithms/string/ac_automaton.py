"""Aho–Corasick 自动机：多模式串线性扫描匹配。"""

from __future__ import annotations

from collections import deque
from typing import Dict, List, Tuple


class ACAutomaton:
    def __init__(self) -> None:
        self._next: List[Dict[str, int]] = [{}]
        self._fail: List[int] = [0]
        self._out: List[List[Tuple[int, int]]] = [[]]  # (pattern_id, length)

    def add(self, pat: str, pid: int) -> None:
        if not pat:
            raise ValueError("empty pattern not supported")
        node = 0
        for ch in pat:
            if ch not in self._next[node]:
                self._next[node][ch] = len(self._next)
                self._next.append({})
                self._fail.append(0)
                self._out.append([])
            node = self._next[node][ch]
        self._out[node].append((pid, len(pat)))

    def build(self) -> None:
        q: deque[int] = deque()
        for ch, nxt in self._next[0].items():
            self._fail[nxt] = 0
            q.append(nxt)
        while q:
            u = q.popleft()
            for ch, v in self._next[u].items():
                q.append(v)
                f = self._fail[u]
                while f and ch not in self._next[f]:
                    f = self._fail[f]
                self._fail[v] = self._next[f][ch] if ch in self._next[f] else 0
                self._out[v].extend(self._out[self._fail[v]])

    def find_all(self, text: str) -> List[Tuple[int, int, int]]:
        """返回 (起始下标, pattern_id, 长度) 列表。"""
        res: List[Tuple[int, int, int]] = []
        state = 0
        for i, ch in enumerate(text):
            while state and ch not in self._next[state]:
                state = self._fail[state]
            if ch in self._next[state]:
                state = self._next[state][ch]
            for pid, ln in self._out[state]:
                res.append((i - ln + 1, pid, ln))
        return res


if __name__ == "__main__":
    pats = ["he", "she", "his", "hers"]
    ac = ACAutomaton()
    for i, p in enumerate(pats):
        ac.add(p, i)
    ac.build()
    hits = ac.find_all("ushers")
    got = sorted((pos, pid) for pos, pid, _ in hits)
    want = sorted([(1, 1), (2, 0), (2, 3)])
    assert got == want
    try:
        ac.add("", 0)
        raise AssertionError("expected ValueError")
    except ValueError:
        pass
    print("ac_automaton OK")
