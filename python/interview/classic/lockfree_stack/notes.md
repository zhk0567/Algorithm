# 无锁入门：Treiber 栈（C++ 真无锁 + Python 参考实现）

## 为什么分两种

- **C++**：`std::atomic<Node*>` + `compare_exchange_weak`，多线程下为经典 **Treiber 无锁栈**（需注意 **ABA**，生产环境常配 **epoch / hazard pointer**）。
- **Python**：无标准 CAS 操作裸指针；同目录 **`treiber_ref.py`** 用**一把大锁**包一层，**逻辑与 Treiber 的 push/pop 分支一致**，用于写对用例、再对照阅读 C++。

## 复杂度

均摊 `push` / `pop`：O(1)（不计 CAS 重试与竞争）。

## 面试要点

- **适用场景**：无锁栈/链表入门、高并发栈式任务窃取（概念上）；生产需处理 **ABA**。
- **复杂度**：单次 CAS 成功 O(1)；失败重试次数与竞争相关。
- **对照**：C++ `treiber_stack.cpp` 真 CAS；`treiber_ref.py` 逻辑同构、**大锁对照**；LeetCode 无标配题。
- **常见坑**：**ABA**（内存复用）、只支持栈语义、多生产者多消费者需更强结构（MPMC 队列）；Python 无裸 CAS 勿声称「真无锁」。
