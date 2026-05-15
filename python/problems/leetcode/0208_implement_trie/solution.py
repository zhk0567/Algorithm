"""LeetCode 208: Implement Trie (Prefix Tree)."""

from __future__ import annotations


class Trie:
    def __init__(self) -> None:
        self._root: dict[str, dict] = {}

    def insert(self, word: str) -> None:
        cur: dict[str, dict] = self._root
        for ch in word:
            cur = cur.setdefault(ch, {})
        cur["#"] = {}

    def search(self, word: str) -> bool:
        cur = self._root
        for ch in word:
            if ch not in cur:
                return False
            cur = cur[ch]  # type: ignore[assignment]
        return "#" in cur

    def startsWith(self, prefix: str) -> bool:
        cur = self._root
        for ch in prefix:
            if ch not in cur:
                return False
            cur = cur[ch]  # type: ignore[assignment]
        return True


if __name__ == "__main__":
    t = Trie()
    t.insert("apple")
    assert t.search("apple")
    assert not t.search("app")
    assert t.startsWith("app")
    t.insert("")
    assert t.search("")
    assert t.startsWith("")
    print("0208 OK")
