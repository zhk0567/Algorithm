"""叉积与三点点向关系。"""

from __future__ import annotations


def cross(ax: int, ay: int, bx: int, by: int) -> int:
    return ax * by - ay * bx


def orient(ax: int, ay: int, bx: int, by: int, cx: int, cy: int) -> int:
    """>0 逆时针，=0 共线，<0 顺时针。"""
    return cross(bx - ax, by - ay, cx - ax, cy - ay)


if __name__ == "__main__":
    assert orient(0, 0, 1, 0, 1, 1) > 0
    assert orient(0, 0, 1, 0, 2, 0) == 0
    print("geometry OK")
