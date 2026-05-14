# 纯 TAS 自旋锁（C++）

**TAS**（Test-And-Set）：`atomic_flag::test_and_set` 返回旧值；为 `false` 时表示成功占有锁，为 `true` 时自旋重试。释放用 `clear`（`memory_order_release`）。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\interview\classic\tas_spinlock
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe tas_spinlock.cpp
.\run.exe
```

## 注意

- 用户态自旋会烧 CPU；高竞争可改为 **TTAS**（先 `load` 再 `test_and_set`）或退避 / `mutex`。
- 与 [Python 对照版](../../../../python/interview/classic/tas_spinlock/) 对照：Python 无标准 `atomic_flag`，对照实现见该目录说明。
