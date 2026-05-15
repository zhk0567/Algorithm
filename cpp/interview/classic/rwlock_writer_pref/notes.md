# 读写锁（写者优先，C++）

与 [Python 版](../../../python/interview/classic/rwlock_writer_pref/) 对照。

> **面试要点**：见 [Python 版 notes.md](../../../python/interview/classic/rwlock_writer_pref/notes.md)。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\interview\classic\rwlock_writer_pref
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe rwlock_writer_pref.cpp
.\run.exe
```

## 注意

教学用三 `mutex` 模型；生产环境可优先 `std::shared_mutex` 并确认实现策略是否满足读者/写者公平需求。
