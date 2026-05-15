# 限流器：令牌桶（C++）

> 同 Python 版思路：`std::mutex` 串行化，`std::chrono::steady_clock` 取单调时间；按时间差延迟补充令牌。

> **面试要点**：见 [Python 版 notes.md](../../../python/interview/classic/rate_limiter/notes.md)。

## 编译运行

```powershell
Set-Location cpp\interview\classic\rate_limiter
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe rate_limiter.cpp
.\run.exe
```
