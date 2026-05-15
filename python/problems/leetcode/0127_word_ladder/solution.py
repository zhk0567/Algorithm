"""LeetCode 127: Word Ladder."""

from __future__ import annotations

from collections import deque


class Solution:
    def ladderLength(
        self,
        beginWord: str,
        endWord: str,
        wordList: list[str],
    ) -> int:
        words = set(wordList)
        if endWord not in words:
            return 0
        q: deque[tuple[str, int]] = deque([(beginWord, 1)])
        seen = {beginWord}
        alpha = "abcdefghijklmnopqrstuvwxyz"
        while q:
            w, depth = q.popleft()
            if w == endWord:
                return depth
            for i in range(len(w)):
                for c in alpha:
                    nw = w[:i] + c + w[i + 1 :]
                    if nw in words and nw not in seen:
                        seen.add(nw)
                        q.append((nw, depth + 1))
        return 0


if __name__ == "__main__":
    wl = ["hot", "dot", "dog", "lot", "log", "cog"]
    assert Solution().ladderLength("hit", "cog", wl) == 5
    assert Solution().ladderLength("hit", "cog", ["hot", "dot", "dog"]) == 0
    assert Solution().ladderLength("a", "c", ["a", "b", "c"]) == 2
    print("0127 OK")
