# 面试专题（C++）

| 子目录 | 说明 |
|--------|------|
| [`classic/`](classic/) | 手写 LRU、LFU、线程安全队列、单例、令牌桶等 |
| [`top_frequent/`](top_frequent/) | 高频题按专题索引，链回 [`../problems/leetcode/`](../problems/leetcode/) |

## `classic/` 一览

| 专题 | 路径 |
|------|------|
| LRU（双链表 + 哈希） | [`classic/lru_cache/`](classic/lru_cache/) |
| LFU（O(1)） | [`classic/lfu_cache/`](classic/lfu_cache/) |
| 有界阻塞队列 | [`classic/thread_safe_queue/`](classic/thread_safe_queue/) |
| 单例 | [`classic/singleton/`](classic/singleton/) |
| 令牌桶限流 | [`classic/rate_limiter/`](classic/rate_limiter/) |

各子目录 `GUIDE.md` 含 `g++` 编译命令（需本机已安装 MinGW/LLVM 并将 `g++` 加入 `PATH`）。
