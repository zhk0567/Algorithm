# 环形缓冲区（Ring Buffer）

定长数组 + 头尾下标，**队尾入队、队头出队**，下标对容量取模。满时 `push` 抛 `BufferError`、空时 `pop` 抛 `BufferError`。

## 复杂度

- `push` / `pop`：均摊 O(1)
- 空间 O(capacity)

## 面试要点

- 区分 `head`/`tail` 与「空 / 满」判定（本实现用额外 `size`）。
- 单生产者单消费者可做无锁环形队列；本题为**单线程语义**的清晰 API。
