"""几何分布期望：首次成功试验次数。"""

from __future__ import annotations


def expected_first_success(p_num: int, p_den: int) -> float:
    """成功概率 p = p_num / p_den，返回期望 1/p。"""
    return p_den / p_num


if __name__ == "__main__":
    assert abs(expected_first_success(1, 6) - 6.0) < 1e-12
    print("probability OK")
