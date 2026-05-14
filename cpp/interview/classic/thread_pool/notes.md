# 简易线程池（C++）

与 [Python 版](../../../python/interview/classic/thread_pool/) 同目标：`enqueue` 投递 `std::function<void()>`，`shutdown` 先 **`wait_idle()`**（队列空且无在执行任务）再停线程。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\interview\classic\thread_pool
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe thread_pool.cpp
.\run.exe
```
