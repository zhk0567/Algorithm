# 手写信号量（Semaphore）

计数信号量：`acquire()` 将计数减一（为 0 则阻塞），`release(n)` 将计数加 `n` 并唤醒等待线程。实现为 **`threading.Condition` + 整数计数**；标准库另有 [`threading.Semaphore`](https://docs.python.org/3/library/threading.html#threading.Semaphore) 可对读源码。

## 面试要点

- **适用场景**：资源池（连接数、车位）、限并发、生产者-消费者（空槽/满槽计数）。
- **复杂度**：`acquire`/`release` O(1)（不计阻塞调度）。
- **标准库对照**：[`threading.Semaphore`](https://docs.python.org/3/library/threading.html#threading.Semaphore)、[`BoundedSemaphore`](https://docs.python.org/3/library/threading.html#threading.BoundedSemaphore)。
- **常见坑**：初值为 1 时等价互斥；`release` 次数可大于 `acquire`（本实现允许）；忘记在 `finally` 里 `release`。

## 复杂度

`acquire` / `release`：O(1) 不计阻塞；阻塞时进入内核调度。
