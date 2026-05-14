# 读写锁（C++）

与 [Python 版](../../../python/interview/classic/rwlock/) 同构；亦可用 `std::shared_mutex` 作标准库对照。

## 相关

- 写者优先实现：[`../rwlock_writer_pref/`](../rwlock_writer_pref/)

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\interview\classic\rwlock
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe rwlock.cpp
.\run.exe
```
