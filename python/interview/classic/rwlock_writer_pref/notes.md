# 读写锁（写者优先，Python）

与 [读者优先版 `../rwlock/`](../rwlock/) 对照：本实现避免**写者饥饿**。

## 思路（三把锁）

1. **`read_gate`**：写者进入写锁前先占用，**新读者**在 `read_lock` 入口与此竞争；写者持有期间读者在 `_read_gate.acquire()` 上阻塞。
2. **`guard` + `readers`**：与读者优先版相同，保护读者计数；首个读者占 `resource`，末读者释放。
3. **`resource`**：读者群与写者互斥（首个读者相当于拿「共享读令牌」）。

写者路径：`read_gate` → `resource`；读者路径：过 `read_gate` 后只做读者计数与 `resource` 的首/末配对。

## 局限

- **读者饥饿**：写者连续到达时读者可能长期等待；工程上可再叠公平队列或 `shared_mutex` 策略。

## 与 C++

见 [C++ 版](../../../../cpp/interview/classic/rwlock_writer_pref/)。
