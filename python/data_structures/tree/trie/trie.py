"""Trie：小写字母 a-z。"""

from __future__ import annotations


class Trie:
    def __init__(self) -> None:
        self._root: dict[str, dict] = {}

    def insert(self, word: str) -> None:
        cur: dict[str, dict] = self._root
        for ch in word:
            cur = cur.setdefault(ch, {})
        cur["$"] = {}  # end marker

    def search(self, word: str) -> bool:
        cur = self._root
        for ch in word:
            if ch not in cur:
                return False
            cur = cur[ch]  # type: ignore[assignment]
        return "$" in cur

    def starts_with(self, prefix: str) -> bool:
        cur = self._root
        for ch in prefix:
            if ch not in cur:
                return False
            cur = cur[ch]  # type: ignore[assignment]
        return True


if __name__ == "__main__":
    t = Trie()
    t.insert("apple")
    assert t.search("apple") and not t.search("app")
    assert t.starts_with("app")
    t.insert("")
    assert t.search("") and t.starts_with("")
    print("Trie OK")
