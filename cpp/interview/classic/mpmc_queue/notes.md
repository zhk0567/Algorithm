# 有界 MPMC 无锁队列（C++，`int`）

**模型**：环形槽数组，每槽 `atomic<size_t> turn` 与载荷；`head` / `tail` 各 `fetch_add` 取槽下标。生产者在 `turn == 2 * lap` 时写入并置 `2*lap+1`；消费者在 `turn == 2*lap+1` 时读出并置 `2*lap+2`。与 [Erik Rigtorp / MPMCQueue](https://github.com/rigtorp/MPMCQueue) 同族（MIT License）。

> **面试要点**：见 [Python 版 notes.md](../../../python/interview/classic/mpmc_queue/notes.md)。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\interview\classic\mpmc_queue
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe mpmc_queue.cpp
.\run.exe
```

## 注意

- 满 / 空时当前实现为 **自旋等待**（`yield`），非阻塞 `try_push`/`try_pop` 可按同逻辑加 CAS 分支。
- 槽与 `head`/`tail` 对齐为减少伪共享；生产代码可再对照原库的 `try_emplace` / `size` 语义。
- [Python 对照](../../../../python/interview/classic/mpmc_queue/) 为 **有界阻塞队列**（非无锁），用于同一总数压测对拍。
