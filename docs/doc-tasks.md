# 任务清单（分阶段）

> 与 [仓库手册 · 学习路线](doc-handbook.md#study-roadmap) 对照使用；按阶段从上到下推进即可。根目录仅 **[README.md](../README.md)**；子目录说明为 **`notes.md`**。  
> **维护**：完成功能或阶段性核对后，直接在本文件改勾选与措辞，并与 [仓库手册](doc-handbook.md) 中 **「当前进度（简记）」** 一节保持大致一致。

---

## 第零阶段：环境与工具链（可选）

- [x] 本机 **MinGW-w64**（或 LLVM），`g++` / `clang++` 已在 **PATH** 中可用
- [x] **`scripts/smoke_compile_cpp.ps1`**：`cpp/interview/classic`、`data_structures`、`algorithms`、`problems/leetcode` 下全部 `.cpp` 本地 **g++ -c 冒烟**通过；上述范围内使用 `assert` 的题解/示例已补 **`#include <cassert>`**（部分 MinGW 下 `bits/stdc++.h` 不导出 `assert`）；LC **0022** 等将 `assert(…含逗号列表…)` 改为中间变量，避免宏参数被逗号拆开
- [ ] 对 **整个** `cpp/**`（含 `problems/leetcode/**`）按各 `notes.md` 命令做**全量编译冒烟**（体量大，按需排期）
- [ ] 若长期只用 **MSVC**：为 `cpp/` 规划「无 `bits/stdc++.h`」或统一标准头（工作量较大，单列里程碑）

---

## 第一阶段：`data_structures/`（已完成）

- [x] `python/data_structures/`、`cpp/data_structures/` 各专题已具备 `notes.md` + 双语言示例

---

## 第二阶段：`algorithms/`（主干已完成）

- [x] 排序与查找、递归/分治/贪心/回溯、双指针 / 滑动窗口 / 前缀和
- [x] 动态规划各子目录（linear / interval / tree / digit / bitmask / knapsack）
- [x] 图论（traversal / shortest_path / mst / topological_sort / scc / network_flow）
- [x] 字符串、数学各子目录、位运算、`advanced/` 等
- [ ] 子目录级「推荐题单链接」或题号索引（刷题时补）
- [ ] 莫队、LCA 等扩展专题（按需再拆文件）

---

## 第三阶段：`problems/` 刷题归档（Hot 100 已完成）

- [x] 以 LeetCode 为主线：`leetcode/<四位编号>_<snake_case>/` + `notes.md` + `solution.*`
- [x] 维护 `problems/hot100/notes.md` 与 `leetcode/` 对应（Hot 100：99 题 Python+C++，LC 175 SQL-only；脚本 `scripts/gen_hot100_readme.py`）
- [x] `offer/`、`nowcoder/`、`codetop/`、`luogu/` 目录级 `notes.md` 与命名约定
- [ ] 按需向 `leetcode/` 及上述题单目录**持续加题**、补全索引与交叉链接

---

## 第四阶段：`interview/`（主体已落地，可继续加专题）

### `interview/classic/`（Python + C++ + `notes.md`）

- [x] LRU、LFU、有界阻塞队列、单例、令牌桶
- [x] 环形缓冲区、线程池、计数信号量、读写锁（读者优先）
- [x] Treiber 无锁栈（C++ `atomic` + Python 锁版参考实现 `treiber_ref.py`）
- [x] **Ticket Lock**（Python：`Condition` 取号叫号；C++：`atomic` + `yield` 自旋等待）
- [x] **写者优先读写锁**（Python / C++：`read_gate` + 读者计数 + `resource`，与读者优先 `rwlock/` 对照）
- [x] **纯 TAS 自旋锁**（C++：`atomic_flag::test_and_set`；Python：短互斥 + 自旋语义对照）
- [x] **有界 MPMC 无锁队列**（C++：序列槽 + turn；Python：`deque`+`Condition` 对拍参考）

### `interview/top_frequent/`

- [x] 双语文首写明与 `leetcode/` 的**同步维护**约定；文末「手写对照」链回 `classic/`
- [x] `top_frequent` 表内链接与 `problems/leetcode/` 目录：**`scripts/check_top_frequent_leetcode.py`**（双语文索引 slug 一致 + `python/cpp/problems/leetcode/<slug>/` 存在）

### 可选扩展（未排期）

- [ ] `classic/`：按需再加无锁结构（如 hazard pointer、无锁链表队列等）或加深现有专题笔记
- [ ] `top_frequent`：按你正在刷的题单扩表（非 Hot 100 题号）

---

## 第五阶段：文档与根入口

- [x] 根 **[README.md](../README.md)** 已与 `doc-handbook`、`doc-tasks` **互链**，且面试 / Hot 100 等进度描述与当前仓库**基本一致**（大改功能后请再过一眼）
- [x] 已扩充 [仓库手册](doc-handbook.md) 中 **Algorithm templates**（单调栈/队列、Trie、KMP）与 **Complexity** 表（并查集、线段树/树状数组、Trie）

---

## 第六阶段：质量与回归（随体量增长）

- [x] 根目录 **`scripts/run_all_python.ps1`**：白名单递归运行带 `if __name__ == "__main__"` 的模块（默认 `python/interview/classic`、`data_structures`、`algorithms`；`-IncludeLeetcode` 含 `problems/leetcode`）
- [x] 根目录 **`scripts/smoke_compile_cpp.ps1`**：与第零阶段已勾选的四棵 `cpp/` 子树编译冒烟一致，可与 Python 脚本一并作为回归入口

---

目录、模板与复杂度速查见 **[doc-handbook.md](doc-handbook.md)**。
