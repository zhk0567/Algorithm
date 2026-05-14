# 仓库手册（目录 · 路线 · 模板）

> **合并说明**：目录约定、学习路线、算法骨架、复杂度与单题写作模板等集中在本页；**勾选类任务**单独维护在 **[doc-tasks.md](doc-tasks.md)**。根目录仍只保留 **[README.md](../README.md)**；子目录说明统一为 **`notes.md`**。

---

## Repo layout

> **`python/` 与 `cpp/` 同构**；根目录不放题目与临时文件。

### 顶层

```
Algorithm/
├── README.md              # 全库唯一入口
├── .gitignore
├── docs/                  # 本手册 + [任务清单](doc-tasks.md)
├── scripts/               # 维护脚本（如 Hot 100 索引）
├── python/                # data_structures / algorithms / problems / interview
└── cpp/                   # 与 python/ 镜像
```

### 同构子树

| 子目录 | 用途 |
|--------|------|
| `data_structures/` | 基础与进阶数据结构（每专题 `notes.md` + 示例代码） |
| `algorithms/` | 按范式与专题组织的算法示例 |
| `problems/` | 刷题：`leetcode/`、`hot100/notes.md` 索引、`offer/`、`codetop/` 等 |
| `interview/` | 面试：`classic/`（含读写锁、写者优先 RWLock、Treiber 栈、Ticket Lock、TAS、MPMC 无锁队列 等）、`top_frequent/`（链回 leetcode，双语文首写同步） |

语言入口：[python/notes.md](../python/notes.md)、[cpp/notes.md](../cpp/notes.md)。

### 题目目录命名（LeetCode 等）

- 目录：`<四位编号>_<snake_case_英文标题>/`，如 `0001_two_sum/`
- 内容：`notes.md` + `solution.py` 或 `solution.cpp`（末尾自测）；SQL 题为 `solution.sql`

### 脚本

| 文件 | 说明 |
|------|------|
| [gen_hot100_readme.py](../scripts/gen_hot100_readme.py) | 生成 `python/problems/hot100/notes.md` 与 `cpp/problems/hot100/notes.md` |
| [check_top_frequent_leetcode.py](../scripts/check_top_frequent_leetcode.py) | 校验 `interview/top_frequent/notes.md` 题链与 `leetcode/` 目录及 py/cpp 表一致 |
| [run_all_python.ps1](../scripts/run_all_python.ps1) | 白名单递归运行带 `__main__` 自测的 Python 模块（默认 classic + data_structures + algorithms；可选 `-IncludeLeetcode`） |
| [smoke_compile_cpp.ps1](../scripts/smoke_compile_cpp.ps1) | `g++ -c` 编译冒烟：`cpp/interview/classic`、`data_structures`、`algorithms`、`problems/leetcode` |

```powershell
Set-Location F:\Study\Algorithm
python scripts\gen_hot100_readme.py
python scripts\check_top_frequent_leetcode.py
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_all_python.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1
```

脚本说明见 [scripts/doc-scripts.md](../scripts/doc-scripts.md)。编译产物由根 `.gitignore` 忽略，勿提交 `*.exe` 等。

---

## Study roadmap

可按个人节奏调整；路径与 `python/`、`cpp/` 下同构目录对应。

### 基础

1. **线性结构**：数组、链表、栈、队列、哈希表（`data_structures/linear/`）
2. **排序与查找**：`algorithms/sorting/`、`algorithms/searching/`
3. **递归与分治**：`algorithms/recursion/`、`algorithms/divide_and_conquer/`

### 进阶

1. **树与堆**：`data_structures/tree/`
2. **图**：表示、遍历、最短路、拓扑（`data_structures/graph/`、`algorithms/graph/`）
3. **双指针 / 滑动窗口 / 前缀和**：`two_pointers`、`sliding_window`、`prefix_sum`

### 专题

1. **动态规划**：线性、区间、树形、背包、数位、状压（`algorithms/dynamic_programming/`）
2. **贪心、回溯、位运算**：对应子目录
3. **字符串**：KMP、Trie 等（`algorithms/string/`）
4. **数学**：数论、组合、矩阵等（`algorithms/math/`）

### 刷题与面试

- 日常：`problems/leetcode/` 等按来源归档
- 面试：`interview/classic/`（LRU、LFU、队列、单例、限流、环形缓冲、线程池、信号量、读写锁、写者优先读写锁、Treiber 栈、**Ticket Lock**、**TAS 自旋锁**、**MPMC 无锁队列**）、`interview/top_frequent/`（表与 `leetcode/` 同步维护）

### 当前进度（简记）

- `data_structures/`、`algorithms/`：已双语言铺全
- `problems/leetcode/`：Hot 100 已对齐（99 题 Python+C++，LC 175 SQL-only），索引见 `problems/hot100/notes.md`
- `interview/`：classic（含读写锁/写者优先、Treiber 栈、Ticket Lock、TAS、MPMC 无锁队列 等）+ `top_frequent/`（双语文首含同步说明）；回归可跑 `scripts/run_all_python.ps1` / `scripts/smoke_compile_cpp.ps1`

**后续勾选与工程化待办** → **[doc-tasks.md](doc-tasks.md)**。

---

## Algorithm templates

> 思路骨架；具体代码见各语言专题目录。

### 二分（左闭右开）

- 不变量：`[lo, hi)` 内保留答案；`check(mid)` 与边界更新一致。

### 回溯

```text
def dfs(路径, 选择列表):
    if 满足结束条件: 记录答案; return
    for 选择 in 选择列表:
        if 剪枝: continue
        做选择
        dfs(路径, 选择列表)
        撤销选择
```

### 并查集

- `find` 路径压缩；`union` 按秩合并。

### BFS

- 队列、访问标记、层数或距离数组。

### Dijkstra（非负权）

- 优先队列 `(dist, node)`，松弛边。

### 滑动窗口

- 右扩满足条件，左缩维持/破坏条件；`deque` 或频次数组维护窗口性质。

### 单调栈 / 单调队列

- 栈底到栈顶单调增或单调减；新元素入栈时弹出不保持单调性的旧元素；常用于「下一个更大元素」、柱状图最大矩形、滑动窗口最值（单调队列）。

### Trie（前缀树）

- 边表示字符；从根沿边走即前缀；插入 / 前缀查询字符串长度 L 时一般为 O(L)（字母表大小为常数时）。

### KMP

- `next[i]`：模式串在位置 i 失配时模式应回退到的下标；主串指针不回退，整体 O(n+m)。

---

## Complexity

| 记号 | 含义 |
|------|------|
| O(1) | 常数 |
| O(log n) | 二分、平衡树高度 |
| O(n) | 线性 |
| O(n log n) | 高效排序、常见分治 |
| O(n²) | 朴素双重循环 |
| O(2ⁿ) / O(n!) | 指数 / 阶乘（多靠剪枝） |

### 常见操作

| 结构 / 操作 | 平均时间 | 最坏时间 | 空间 |
|-------------|----------|----------|------|
| 数组随机访问 | O(1) | O(1) | — |
| 哈希插入/查找 | O(1) | O(n) | O(n) |
| 平衡 BST 插入/查找 | O(log n) | O(log n) | O(n) |
| 堆 push/pop | O(log n) | O(log n) | O(n) |
| 比较排序 | O(n log n) | O(n log n) | O(1)~O(n) |
| 并查集 `find`/`union`（路径压缩 + 按秩） | 均摊 α(n)* | 同上 | O(n) |
| 线段树 / 树状数组 单点或区间 | O(log n) | O(log n) | O(n) |
| Trie 插入 / 前缀查询 | O(L) | O(L) | 结点数 |
| DFS/BFS（图） | O(V+E) | O(V+E) | O(V) |
| Dijkstra（堆） | O((V+E) log V) | 同上 | O(V) |

\* α 为反阿克曼函数，实际可视为很小的常数级。

### 分析习惯

- 数清 **DP 状态规模**、**回溯分支因子**、**单调栈摊还**。
- 空间勿忘 **递归栈** 与 **辅助结构**。

---

## Problem notes template

复制到新题目目录，保存为 **`notes.md`** 后填空。

### 题面

- **来源**：（如 LeetCode 1）
- **链接**：
- **简述**：

### 思路

1. 解法一：
2. 解法二（可选）：

### 复杂度

| 解法 | 时间 | 空间 |
|------|------|------|
| | | |

### 陷阱与注意

-

### 相关题目

-
