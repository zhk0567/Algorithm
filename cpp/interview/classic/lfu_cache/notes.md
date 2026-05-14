# 手写 LFU Cache（O(1)，C++）

> LeetCode 460。同 Python 版思路：`unordered_map<int, list<Node>::iterator>` + `unordered_map<int, list<Node>>` 实现频次桶；`min_freq` 追踪当前最小频次。

## 编译运行

```powershell
Set-Location cpp\interview\classic\lfu_cache
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe lfu_cache.cpp
.\run.exe
```
