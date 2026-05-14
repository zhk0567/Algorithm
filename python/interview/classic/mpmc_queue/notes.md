# 有界 MPMC 队列（Python）

## 与 C++ 无锁版的区别

[C++ 版](../../../../cpp/interview/classic/mpmc_queue/) 为 **序列槽 + `atomic` turn** 的 MPMC 无锁有界环（思路见 Rigtorp `MPMCQueue`）。

本目录 `BoundedMpmcQueueRef` 使用 **`collections.deque` + `threading.Condition`**，为经典 **有界阻塞队列**，便于与 C++ 压力测在 **「8 生产者 ×500 push + 8 消费者 ×500 pop、元素均为 1」** 下对拍总和。

## 相关

- Treiber 栈（无锁入门）：[`../lockfree_stack/`](../lockfree_stack/)
- TAS 自旋锁：[`../tas_spinlock/`](../tas_spinlock/)
