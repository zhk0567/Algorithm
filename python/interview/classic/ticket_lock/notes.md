# Ticket Lock（公平排队锁）

**语义**：线程按到达顺序取递增票号 `ticket`，仅当 `now_serving == ticket` 时进入临界区；`release` 将 `now_serving` 加一并唤醒等待者，从而 **FIFO**。

本目录 **Python** 用 `Condition` 实现（易读、易测）；**C++** 用 `atomic` + 自旋（`yield`）展示票号锁骨架，可与互斥量版对照。

## 与自旋锁

纯 **TAS 自旋锁**不保证公平；Ticket Lock 解决**饥饿**（在强公平语义下）。高竞争时自旋浪费 CPU，工程上常结合 **退避** 或短暂 `sleep`。
