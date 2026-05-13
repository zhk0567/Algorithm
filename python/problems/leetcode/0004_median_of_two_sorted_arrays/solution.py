"""LeetCode 4: Median of Two Sorted Arrays."""

from __future__ import annotations


class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        a, b = nums1, nums2
        if len(a) > len(b):
            a, b = b, a
        m, n = len(a), len(b)
        lo, hi = 0, m
        half = (m + n + 1) // 2
        while lo <= hi:
            i = (lo + hi) // 2
            j = half - i
            a_left = a[i - 1] if i else -10**18
            a_right = a[i] if i < m else 10**18
            b_left = b[j - 1] if j else -10**18
            b_right = b[j] if j < n else 10**18
            if a_left <= b_right and b_left <= a_right:
                if (m + n) % 2 == 1:
                    return float(max(a_left, b_left))
                return (max(a_left, b_left) + min(a_right, b_right)) / 2.0
            if a_left > b_right:
                hi = i - 1
            else:
                lo = i + 1
        return 0.0


if __name__ == "__main__":
    assert Solution().findMedianSortedArrays([1, 3], [2]) == 2.0
    assert Solution().findMedianSortedArrays([1, 2], [3, 4]) == 2.5
    print("0004 OK")
