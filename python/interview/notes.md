# 面试专题（Python）

| 子目录 | 说明 |
|--------|------|
| [`classic/`](classic/) | 手写 LRU、LFU、队列、单例、限流、环形缓冲、线程池、信号量、读写锁、写者优先读写锁、Treiber 栈、Ticket Lock、TAS 自旋锁、MPMC 无锁队列（对拍参考）等 |
| [`top_frequent/`](top_frequent/) | 高频题按专题索引，链回 [`../problems/leetcode/`](../problems/leetcode/) |

> **并发与无锁（`classic/`）**：下列实现为**教学向**示例，用于口述思路与小规模自测，**不构成**生产环境性能或线程安全承诺；勿将本地对拍结论直接外推为线上压测结论。

## `classic/` 一览

| 专题 | 路径 |
|------|------|
| LRU（双链表 + 哈希） | [`classic/lru_cache/`](classic/lru_cache/) |
| LFU（O(1)） | [`classic/lfu_cache/`](classic/lfu_cache/) |
| 有界阻塞队列 | [`classic/thread_safe_queue/`](classic/thread_safe_queue/) |
| 单例 | [`classic/singleton/`](classic/singleton/) |
| 令牌桶限流 | [`classic/rate_limiter/`](classic/rate_limiter/) |
| 环形缓冲区 | [`classic/ring_buffer/`](classic/ring_buffer/) |
| 线程池 | [`classic/thread_pool/`](classic/thread_pool/) |
| 信号量 | [`classic/semaphore/`](classic/semaphore/) |
| 读写锁 | [`classic/rwlock/`](classic/rwlock/) |
| 写者优先读写锁 | [`classic/rwlock_writer_pref/`](classic/rwlock_writer_pref/) |
| Treiber 栈（无锁入门） | [`classic/lockfree_stack/`](classic/lockfree_stack/) |
| Ticket Lock（公平锁） | [`classic/ticket_lock/`](classic/ticket_lock/) |
| TAS 自旋锁 | [`classic/tas_spinlock/`](classic/tas_spinlock/) |
| MPMC 无锁队列（对拍） | [`classic/mpmc_queue/`](classic/mpmc_queue/) |

运行自测（在仓库根目录）：

```powershell
Set-Location F:\Study\Algorithm
python python\interview\classic\lru_cache\lru_cache.py
python python\interview\classic\lfu_cache\lfu_cache.py
python python\interview\classic\thread_safe_queue\thread_safe_queue.py
python python\interview\classic\singleton\singleton.py
python python\interview\classic\rate_limiter\rate_limiter.py
python python\interview\classic\ring_buffer\ring_buffer.py
python python\interview\classic\thread_pool\thread_pool.py
python python\interview\classic\semaphore\semaphore.py
python python\interview\classic\rwlock\rwlock.py
python python\interview\classic\rwlock_writer_pref\rwlock_writer_pref.py
python python\interview\classic\lockfree_stack\treiber_ref.py
python python\interview\classic\ticket_lock\ticket_lock.py
python python\interview\classic\tas_spinlock\tas_spinlock.py
python python\interview\classic\mpmc_queue\mpmc_queue.py
```
