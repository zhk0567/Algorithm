# 简易线程池（Thread Pool）

> 面试常考：**固定 worker 数**、任务队列、`submit` / `shutdown`；本实现用 `queue.Queue` + `threading.Thread`。`shutdown(wait=True)` 时先 **`Queue.join()`** 等已提交任务全部执行完，再向各 worker 发 `None` 哨兵退出（避免未执行完就结束）。

## 注意

- 生产环境可改用 `concurrent.futures.ThreadPoolExecutor`；此处为**手写一遍**掌握同步原语。
- `submit` 在 `shutdown` 之后应拒绝（本实现抛 `RuntimeError`）。

## 复杂度

- `submit`：O(1) 入队（忽略锁竞争）
- 空间：O(队列积压 + worker 数)
