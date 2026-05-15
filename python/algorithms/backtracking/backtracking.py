"""回溯：子集、组合、排列、N 皇后。"""

from __future__ import annotations


def subsets(nums: list[int]) -> list[list[int]]:
    out: list[list[int]] = []
    path: list[int] = []

    def dfs(i: int) -> None:
        if i == len(nums):
            out.append(path.copy())
            return
        dfs(i + 1)
        path.append(nums[i])
        dfs(i + 1)
        path.pop()

    dfs(0)
    return out


def combinations(n: int, k: int) -> list[list[int]]:
    out: list[list[int]] = []
    path: list[int] = []

    def dfs(start: int) -> None:
        if len(path) == k:
            out.append(path.copy())
            return
        for x in range(start, n + 1):
            path.append(x)
            dfs(x + 1)
            path.pop()

    dfs(1)
    return out


def permute(nums: list[int]) -> list[list[int]]:
    out: list[list[int]] = []
    used = [False] * len(nums)
    path: list[int] = []

    def dfs() -> None:
        if len(path) == len(nums):
            out.append(path.copy())
            return
        for i in range(len(nums)):
            if used[i]:
                continue
            used[i] = True
            path.append(nums[i])
            dfs()
            path.pop()
            used[i] = False

    dfs()
    return out


def n_queens(n: int) -> int:
    """返回不同解的个数（n 小）。"""
    cols = set()
    diag1 = set()
    diag2 = set()
    ans = 0

    def dfs(r: int) -> None:
        nonlocal ans
        if r == n:
            ans += 1
            return
        for c in range(n):
            if c in cols or (r - c) in diag1 or (r + c) in diag2:
                continue
            cols.add(c)
            diag1.add(r - c)
            diag2.add(r + c)
            dfs(r + 1)
            cols.remove(c)
            diag1.remove(r - c)
            diag2.remove(r + c)

    dfs(0)
    return ans


if __name__ == "__main__":
    assert len(subsets([1, 2])) == 4 and {tuple(s) for s in subsets([1, 2])} == {(), (1,), (2,), (1, 2)}
    assert len(combinations(4, 2)) == 6
    perms = {tuple(p) for p in permute([1, 2, 3])}
    assert len(perms) == 6
    assert n_queens(4) == 2
    assert subsets([]) == [[]]
    assert combinations(3, 0) == [[]]
    assert permute([]) == [[]]
    print("backtracking OK")
