# TAS 自旋锁（Python）

## 与 C++ 纯 TAS 的差异

C++ 版使用 `std::atomic_flag::test_and_set` / `clear`，**硬件级原子**一条指令语义。

CPython 标准库不向用户暴露与 `atomic_flag` 等价的跨版本原子 CAS；本目录实现用 **`threading.Lock` 包住对 `_locked` 的读-改-写**，循环外即为「占不到锁就继续尝试」的**自旋等待**形态，用于**正确性自测与面试口述对齐**，不是内核/无锁意义上的纯 TAS。

## 相关

- C++ `atomic_flag` 版：[`../../../../cpp/interview/classic/tas_spinlock/`](../../../../cpp/interview/classic/tas_spinlock/)
- 公平自旋票号：[`../ticket_lock/`](../ticket_lock/)

## 面试要点

- **适用场景**：极短临界区、内核/嵌入式底层、理解 CAS 与缓存一致性。
- **复杂度**：无竞争 O(1)；高竞争时 **O(竞争度)** 自旋浪费 CPU。
- **对照**：C++ `std::atomic_flag`；Python 版为**教学用**（大锁模拟），真无锁看 C++ 目录。
- **常见坑**：**不公平**、缓存行颠簸（多核）、应用层勿长时间占自旋锁；需 **退避**（yield/exponential backoff）。
