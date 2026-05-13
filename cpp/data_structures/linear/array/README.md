# 动态数组（Dynamic Array / ArrayList）

## 简介

连续内存、按需扩容的可变长数组，适合随机访问与尾部操作。

## 核心思想

维护 `size` 与 `capacity`；满时扩容（通常 2 倍）并搬移；`push_back` 均摊 O(1)。

## 操作与复杂度

| 操作 | 平均 | 最坏 |
|------|------|------|
| `at` | O(1) | O(1) |
| `push_back` | O(1) 摊还 | O(n) |
| `pop_back` | O(1) | O(1) |
| `insert` / `erase` | O(n) | O(n) |

## 典型应用

向量、缓冲区；栈/队列底层。

## 代码要点

使用 `vector` 承载元素，封装扩容与边界检查。

## 编译运行

```powershell
Set-Location cpp\data_structures\linear\array
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe dynamic_array.cpp
.\run.exe
```
