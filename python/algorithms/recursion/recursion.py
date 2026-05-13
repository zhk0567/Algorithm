"""递归基础：阶乘、斐波那契（记忆化）、汉诺塔步数。"""

from __future__ import annotations
from functools import lru_cache


def factorial(n: int) -> int:
    if n < 0:
        raise ValueError("n")
    if n <= 1:
        return 1
    return n * factorial(n - 1)


@lru_cache(maxsize=None)
def fib(n: int) -> int:
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)


def hanoi_moves(n: int) -> int:
    """经典问题最少步数 2^n - 1。"""
    if n <= 0:
        return 0
    return 2**n - 1


if __name__ == "__main__":
    assert factorial(5) == 120
    assert fib(10) == 55
    assert hanoi_moves(3) == 7
    print("recursion OK")
