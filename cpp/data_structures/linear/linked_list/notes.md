# 链表（单链表 / 双链表）

## 简介

节点通过指针链接；适合频繁头尾插入删除，随机访问弱于数组。

## 核心思想

单链表 `next`；双链表 `prev` + `next`，配合哑节点简化边界。

## 操作与复杂度

| 操作 | 头尾已知 | 查找 |
|------|----------|------|
| 插入/删除 | O(1) | O(n) |

## 典型应用

LRU、撤销栈、邻接表边链表。

## 代码要点

析构可递归爆栈，教学代码用 `unique_ptr` 简化所有权；演示用裸指针 + 手动 `delete` 仅小数据。

## 编译运行

```powershell
Set-Location cpp\data_structures\linear\linked_list
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe linked_list.cpp
.\run.exe
```
