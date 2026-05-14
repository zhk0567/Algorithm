# 手写信号量（Semaphore）

计数信号量：`acquire()` 将计数减一（为 0 则阻塞），`release(n)` 将计数加 `n` 并唤醒等待线程。实现为 **`threading.Condition` + 整数计数**；标准库另有 [`threading.Semaphore`](https://docs.python.org/3/library/threading.html#threading.Semaphore) 可对读源码。

## 面试要点

- 与互斥锁关系：**初值为 1** 的二元信号量即互斥量语义。
- `release` 多于 `acquire` 是否允许：本实现允许（计数可大于初值），与 pthread 类似；若需「不得超过上限」可再加 `max` 校验。

## 复杂度

`acquire` / `release`：O(1) 不计阻塞；阻塞时进入内核调度。
