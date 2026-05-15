# 手写 LRU Cache（C++）

> 与 [problems/leetcode/0146_lru_cache/](../../../problems/leetcode/0146_lru_cache/) 的 `std::list + unordered_map` 版互为对照：这里完全 **手写双链表节点**，不使用 `std::list`。

> **面试要点**：见 [Python 版 notes.md](../../../python/interview/classic/lru_cache/notes.md)。

## 编译运行

```powershell
Set-Location cpp\interview\classic\lru_cache
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe lru_cache.cpp
.\run.exe
```

## 复杂度

- `get` / `put` 均 O(1)
- 空间 O(capacity)
