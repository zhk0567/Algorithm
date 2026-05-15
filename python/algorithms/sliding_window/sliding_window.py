"""滑动窗口：定长最大和、无重复字符最长子串。"""

from __future__ import annotations


def max_sum_subarray_k(nums: list[int], k: int) -> int:
    if k <= 0 or k > len(nums):
        return 0
    s = sum(nums[:k])
    best = s
    for i in range(k, len(nums)):
        s += nums[i] - nums[i - k]
        best = max(best, s)
    return best


def length_longest_no_repeat(s: str) -> int:
    last: dict[str, int] = {}
    lo = 0
    best = 0
    for hi, ch in enumerate(s):
        if ch in last and last[ch] >= lo:
            lo = last[ch] + 1
        last[ch] = hi
        best = max(best, hi - lo + 1)
    return best


if __name__ == "__main__":
    assert max_sum_subarray_k([1, 2, 3, 4, 5], 2) == 9
    assert length_longest_no_repeat("abcabcbb") == 3
    assert max_sum_subarray_k([1, 2], 0) == 0
    assert length_longest_no_repeat("") == 0
    print("sliding_window OK")
