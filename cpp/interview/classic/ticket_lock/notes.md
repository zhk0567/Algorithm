# Ticket Lock（C++）

与 [Python 版](../../../python/interview/classic/ticket_lock/)（`Condition` 实现）对照。

> **面试要点**：见 [Python 版 notes.md](../../../python/interview/classic/ticket_lock/notes.md)。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\interview\classic\ticket_lock
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe ticket_lock.cpp
.\run.exe
```

## 注意

本实现为 **自旋等待**；CPU 占用高时请在工程中改为 `mutex` 睡眠等待或指数退避。
