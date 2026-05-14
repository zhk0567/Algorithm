# 读写锁（RWLock，读者优先）

经典实现：**一把保护 `readers` 计数的互斥量** + **一把「写」互斥量**。首个读者抢写锁，末读者释放写锁；写者始终独占写锁。

## 局限

- **写者饥饿**：读者源源不断时写者可能长期进不去；工程上可换写者优先或公平队列（`Condition` 排队）。

## 相关

- 写者优先实现（三锁模型）：[`../rwlock_writer_pref/`](../rwlock_writer_pref/)

## 与 C++17

C++ 可用 `std::shared_mutex` 的 `shared_lock`/`unique_lock`；本仓库 C++ 版用手写双锁与 Python 同构，便于对照。
