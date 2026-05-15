# 线程安全有界阻塞队列

> 自实现生产者-消费者队列：`threading.Lock` + 两个 `Condition`（非满/非空）。  
> 标准库 `queue.Queue` 已经是线程安全的，这里目的是 **手写一遍**，掌握条件变量配对的正确姿势。

## 关键点

- `not_full` / `not_empty` 共用一把锁。
- `put` 时若满则 `wait` 在 `not_full`，唤醒后再检查（**while 循环**，防止虚假唤醒/多消费者抢占）。
- `get` 对称。
- 元素出入用 `collections.deque` 保证 O(1)。
- 支持 `close()`：解除全部阻塞，后续 `put/get` 抛 `Closed`。

## 自测

`thread_safe_queue.py` 用 4 个生产者 + 4 个消费者总计搬运 4000 个元素，校验总数与无重复。

## 面试要点

- **适用场景**：生产者-消费者、有界背压、线程间安全传递任务。
- **复杂度**：`put`/`get` 均摊 O(1)；阻塞时让出 CPU。
- **标准库对照**：[`queue.Queue`](https://docs.python.org/3/library/queue.html)；本实现强调 **双 Condition + while 防虚假唤醒**。
- **常见坑**：`notify` 与 `wait` 配对错误、用 `if` 代替 `while` 检查条件、满/空边界未在锁内判断。
