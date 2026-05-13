# 面试专题（Python）

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

运行自测（在仓库根目录）：

```powershell
Set-Location F:\Study\Algorithm
python python\interview\classic\lru_cache\lru_cache.py
python python\interview\classic\lfu_cache\lfu_cache.py
python python\interview\classic\thread_safe_queue\thread_safe_queue.py
python python\interview\classic\singleton\singleton.py
python python\interview\classic\rate_limiter\rate_limiter.py
```
