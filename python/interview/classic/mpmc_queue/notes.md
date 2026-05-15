# 有界 MPMC 队列（Python）

## 与 C++ 无锁版的区别

[C++ 版](../../../../cpp/interview/classic/mpmc_queue/) 为 **序列槽 + `atomic` turn** 的 MPMC 无锁有界环（思路见 Rigtorp `MPMCQueue`）。

本目录 `BoundedMpmcQueueRef` 使用 **`collections.deque` + `threading.Condition`**，为经典 **有界阻塞队列**，便于与 C++ 压力测在 **「8 生产者 ×500 push + 8 消费者 ×500 pop、元素均为 1」** 下对拍总和。

## 相关

- Treiber 栈（无锁入门）：[`../lockfree_stack/`](../lockfree_stack/)
- TAS 自旋锁：[`../tas_spinlock/`](../tas_spinlock/)

## 面试要点

- **适用场景**：多生产者多消费者有界通道；与线程池任务队列、Disruptor 环形缓冲同类问题。
- **复杂度**：入队/出队均摊 O(1)；满/空时阻塞（Python 版）或自旋（C++ 无锁版）。
- **对照**：C++ [Rigtorp MPMC](https://github.com/rigtorp/MPMCQueue) 思路；Python 版为 **Condition + deque** 阻塞队列，便于对拍。
- **常见坑**：有界队列 **假唤醒**、容量与缓存行；无锁版需正确 **memory order**；勿与无界 `queue.Queue` 混用场景。
