"""LeetCode 76: Minimum Window Substring."""

from __future__ import annotations

from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""
        need = Counter(t)
        have: Counter[str] = Counter()
        need_kinds = len(need)
        match_kinds = 0
        best_l, best_len = 0, len(s) + 1
        l = 0
        for r, ch in enumerate(s):
            have[ch] += 1
            if ch in need and have[ch] == need[ch]:
                match_kinds += 1
            while match_kinds == need_kinds:
                if r - l + 1 < best_len:
                    best_l, best_len = l, r - l + 1
                left_ch = s[l]
                have[left_ch] -= 1
                if left_ch in need and have[left_ch] < need[left_ch]:
                    match_kinds -= 1
                l += 1
        return "" if best_len > len(s) else s[best_l : best_l + best_len]


if __name__ == "__main__":
    assert Solution().minWindow("ADOBECODEBANC", "ABC") == "BANC"
    assert Solution().minWindow("a", "a") == "a"
    assert Solution().minWindow("a", "aa") == ""
    print("0076 OK")
