# 线程安全有界阻塞队列（C++）

> `std::mutex` + 两个 `std::condition_variable`（非空/非满）；模板化容纳任意类型。

## 编译运行

```powershell
Set-Location cpp\interview\classic\thread_safe_queue
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe thread_safe_queue.cpp
.\run.exe
```

## 关键点

- `std::unique_lock<std::mutex>` + `cv.wait(lock, pred)`，pred 形式自动循环等待，避免虚假唤醒。
- `close()` 触发 `notify_all`，后续 `push/pop` 抛 `std::runtime_error`。
