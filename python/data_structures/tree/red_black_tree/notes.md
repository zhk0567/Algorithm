# 红黑树（Red-Black Tree）

## 简介

自平衡 BST：通过着色 + 旋转保证高度 O(log n)。与 [`../avl/`](../avl/) 对照学习。

## 性质（复习）

- 根为黑；红结点两子为黑（或 NIL）；任一路径黑结点数相同。

## 本目录

| 文件 | 说明 |
|------|------|
| `red_black_tree.py` | 插入、`insert_fixup`、中序、`search` |

删除 fixup 可在刷题阶段再补；面试口述以插入 + 性质为主。

## 复杂度

| 操作 | 时间 |
|------|------|
| 查找 / 插入 | O(log n) |

## 与 C++

见 [同构目录](../../../../cpp/data_structures/tree/red_black_tree/)。
