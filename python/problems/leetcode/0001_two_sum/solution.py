"""LeetCode 1: Two Sum — 哈希表解法。"""


class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen: dict[int, int] = {}
        for i, x in enumerate(nums):
            need = target - x
            if need in seen:
                return [seen[need], i]
            seen[x] = i
        return []


def two_sum_brute(nums: list[int], target: int) -> list[int]:
    """暴力对照，仅用于理解。"""
    n = len(nums)
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []


if __name__ == "__main__":
    assert Solution().twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert two_sum_brute([2, 7, 11, 15], 9) == [0, 1]
    print(Solution().twoSum([2, 7, 11, 15], 9))  # [0, 1]
