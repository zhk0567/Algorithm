"""LeetCode 647: Palindromic Substrings."""

from __future__ import annotations


class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0

        def expand(l: int, r: int) -> int:
            cnt = 0
            while l >= 0 and r < n and s[l] == s[r]:
                cnt += 1
                l -= 1
                r += 1
            return cnt

        for i in range(n):
            ans += expand(i, i)
            ans += expand(i, i + 1)
        return ans


if __name__ == "__main__":
    assert Solution().countSubstrings("abc") == 3
    assert Solution().countSubstrings("aaa") == 6
    assert Solution().countSubstrings("") == 0
    print("0647 OK")
