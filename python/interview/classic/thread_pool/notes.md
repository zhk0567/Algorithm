# 简易线程池（Thread Pool）

> 面试常考：**固定 worker 数**、任务队列、`submit` / `shutdown`；本实现用 `queue.Queue` + `threading.Thread`。`shutdown(wait=True)` 时先 **`Queue.join()`** 等已提交任务全部执行完，再向各 worker 发 `None` 哨兵退出（避免未执行完就结束）。

## 注意

- 生产环境可改用 `concurrent.futures.ThreadPoolExecutor`；此处为**手写一遍**掌握同步原语。
- `submit` 在 `shutdown` 之后应拒绝（本实现抛 `RuntimeError`）。

## 复杂度

- `submit`：O(1) 入队（忽略锁竞争）
- 空间：O(队列积压 + worker 数)

## 面试要点

- **适用场景**：CPU 密集/IO 密集任务削峰、控制并发度、避免无界创建线程。
- **口述骨架**：固定 worker 数 + 任务队列 + `submit` / `shutdown`；`shutdown(wait=True)` 应先 `join` 队列再发退出哨兵。
- **标准库对照**：生产用 [`concurrent.futures.ThreadPoolExecutor`](https://docs.python.org/3/library/concurrent.futures.html#threadpoolexecutor)。
- **常见坑**：`shutdown` 后仍 `submit`、任务抛异常未捕获导致 worker 静默、队列无界导致 OOM。
