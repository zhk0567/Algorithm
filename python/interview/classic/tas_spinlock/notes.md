# TAS 自旋锁（Python）

## 与 C++ 纯 TAS 的差异

C++ 版使用 `std::atomic_flag::test_and_set` / `clear`，**硬件级原子**一条指令语义。

CPython 标准库不向用户暴露与 `atomic_flag` 等价的跨版本原子 CAS；本目录实现用 **`threading.Lock` 包住对 `_locked` 的读-改-写**，循环外即为「占不到锁就继续尝试」的**自旋等待**形态，用于**正确性自测与面试口述对齐**，不是内核/无锁意义上的纯 TAS。

## 相关

- C++ `atomic_flag` 版：[`../../../../cpp/interview/classic/tas_spinlock/`](../../../../cpp/interview/classic/tas_spinlock/)
- 公平自旋票号：[`../ticket_lock/`](../ticket_lock/)
