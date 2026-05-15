# 单例模式（C++）

> 给出三种写法的对比：Meyers 局部静态、`std::call_once` 显式同步、加锁双检（落后写法仅作展示）。

| 方式 | 备注 |
|------|------|
| Meyers 单例 | `static T& instance()` 内 `static T inst;`，C++11 起 **保证线程安全初始化**，推荐 |
| `std::call_once` | 显式控制，多用于初始化函数比较复杂时 |
| 双检锁 | 老式写法，必须用 `std::atomic` 保序，否则 UB |

> **面试要点**：见 [Python 版 notes.md](../../../python/interview/classic/singleton/notes.md)。

## 编译运行

```powershell
Set-Location cpp\interview\classic\singleton
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe singleton.cpp
.\run.exe
```
