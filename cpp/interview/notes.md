# 面试专题（C++）

| 子目录 | 说明 |
|--------|------|
| [`classic/`](classic/) | 手写 LRU、LFU、队列、单例、限流、环形缓冲、线程池、信号量、读写锁、写者优先读写锁、Treiber 栈、Ticket Lock、TAS 自旋锁、MPMC 无锁队列 等 |
| [`top_frequent/`](top_frequent/) | 高频题按专题索引，链回 [`../problems/leetcode/`](../problems/leetcode/) |

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
| MPMC 无锁队列（有界） | [`classic/mpmc_queue/`](classic/mpmc_queue/) |

各子目录 `notes.md` 含 `g++` 编译命令（需本机已安装 MinGW/LLVM 并将 `g++` 加入 `PATH`）。
