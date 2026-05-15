# Ticket Lock（公平排队锁）

**语义**：线程按到达顺序取递增票号 `ticket`，仅当 `now_serving == ticket` 时进入临界区；`release` 将 `now_serving` 加一并唤醒等待者，从而 **FIFO**。

本目录 **Python** 用 `Condition` 实现（易读、易测）；**C++** 用 `atomic` + 自旋（`yield`）展示票号锁骨架，可与互斥量版对照。

## 与自旋锁

纯 **TAS 自旋锁**不保证公平；Ticket Lock 解决**饥饿**（在强公平语义下）。高竞争时自旋浪费 CPU，工程上常结合 **退避** 或短暂 `sleep`。

## 面试要点

- **适用场景**：需要 **FIFO 公平** 的短临界区；面试对比 TAS/Mutex 公平性。
- **复杂度**：`acquire`/`release` O(1) 逻辑；高竞争下自旋或阻塞成本上升。
- **对照**：[`../tas_spinlock/`](../tas_spinlock/) 无公平保证；内核互斥量常带排队。
- **常见坑**：票号溢出（理论需大整数/wrap 处理）；纯自旋耗电；与 CLH/MCS 队列锁的演进关系要能说清一句。
