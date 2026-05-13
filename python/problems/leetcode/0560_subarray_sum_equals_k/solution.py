"""LeetCode 560: Subarray Sum Equals K."""

from __future__ import annotations

from collections import defaultdict


class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        cnt: dict[int, int] = defaultdict(int)
        cnt[0] = 1
        s = ans = 0
        for x in nums:
            s += x
            ans += cnt[s - k]
            cnt[s] += 1
        return ans


if __name__ == "__main__":
    assert Solution().subarraySum([1, 1, 1], 2) == 2
    assert Solution().subarraySum([1, 2, 3], 3) == 2
    assert Solution().subarraySum([1, -1, 1, -1], 0) == 4
    print("0560 OK")
