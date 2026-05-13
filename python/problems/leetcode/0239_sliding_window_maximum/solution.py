"""LeetCode 239: Sliding Window Maximum."""

from __future__ import annotations

from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        dq: deque[int] = deque()
        res: list[int] = []
        for i, x in enumerate(nums):
            while dq and nums[dq[-1]] <= x:
                dq.pop()
            dq.append(i)
            if dq[0] <= i - k:
                dq.popleft()
            if i >= k - 1:
                res.append(nums[dq[0]])
        return res


if __name__ == "__main__":
    assert Solution().maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3) == [
        3, 3, 5, 5, 6, 7,
    ]
    assert Solution().maxSlidingWindow([1], 1) == [1]
    print("0239 OK")
