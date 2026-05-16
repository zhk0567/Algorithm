# 仓库手册（目录 · 路线 · 模板）

> **合并说明**：目录约定、学习路线、算法骨架、复杂度与单题写作模板等集中在本页；**未完成待办**单独维护在 **[doc-tasks.md](doc-tasks.md)**（仅列 `[ ]` 项；**算法与数据结构全量整理**为 P0 主线，见该文件）；**封版前大规模可勾选验收**见 **[project-closeout-checklist.md](project-closeout-checklist.md)**。根目录仍只保留 **[README.md](../README.md)**；子目录说明统一为 **`notes.md`**。

---

## Repo layout

> **`python/` 与 `cpp/` 同构**；根目录不放题目与临时文件。

### 顶层

```
Algorithm/
├── README.md              # 全库唯一入口
├── .gitignore
├── docs/                  # 本手册 + [任务清单](doc-tasks.md) + [算法覆盖总表](algorithm-coverage.md) + [封版收口清单](project-closeout-checklist.md)
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
| [smoke_compile_cpp.ps1](../scripts/smoke_compile_cpp.ps1) | 默认 `cpp/**` 全树 `g++ -c`（`-I cpp/include`）；`-LinkEntry` 链接运行专题入口；可选 `-Compiler msvc` |
| [cpp-toolchain.md](cpp-toolchain.md) | C++ 统一头 `alg_std.hpp`、g++/MSVC 编译说明 |

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
3. **双指针 / 滑动窗口 / 前缀和**：`two_pointers`、`sliding_window`、`prefix_sum`；**莫队**见 `algorithms/advanced/mo_algorithm/`；**树上 LCA**见 `algorithms/graph/lca/`

### 专题

1. **动态规划**：线性、区间、树形、背包、数位、状压（`algorithms/dynamic_programming/`）
2. **贪心、回溯、位运算**：对应子目录
3. **字符串**：KMP、Trie 等（`algorithms/string/`）
4. **数学**：数论、组合、矩阵等（`algorithms/math/`）

### 刷题与面试

- 日常：`problems/leetcode/` 等按来源归档
- 面试：`interview/classic/`（LRU、LFU、队列、单例、限流、环形缓冲、线程池、信号量、读写锁、写者优先读写锁、Treiber 栈、**Ticket Lock**、**TAS 自旋锁**、**MPMC 无锁队列**）、`interview/top_frequent/`（表与 `leetcode/` 同步维护）

### 当前进度（简记）

- `data_structures/`、`algorithms/`：已双语言铺全；**覆盖盘点与缺口队列**见 **[algorithm-coverage.md](algorithm-coverage.md)**
- `problems/leetcode/`：Hot 100 已对齐（99 题 Python+C++，LC 175 SQL-only），**全库归档约 120** 题双语言，索引见 `problems/hot100/notes.md` 与各专题 `notes.md`
- `interview/`：classic（含读写锁/写者优先、Treiber 栈、Ticket Lock、TAS、MPMC 无锁队列 等）+ `top_frequent/`（v1=103 题冻结，双语文首同步）；回归可跑 `scripts/run_all_python.ps1` / `scripts/smoke_compile_cpp.ps1`

**未完成待办** → **[doc-tasks.md](doc-tasks.md)**（P1 配套已收口时可为空表）；**算法/数据结构覆盖盘点** → **[algorithm-coverage.md](algorithm-coverage.md)**。

---

## Algorithm templates

> 思路骨架；具体代码见各语言专题目录。

### 二分（左闭右开）

- 不变量：`[lo, hi)` 内保留答案；`check(mid)` 与边界更新一致。

### 二分答案

- 答案具有单调性：若「容量 ≥ mid 可行」则 mid 增大仍可能可行；在答案域上对 `check` 做二分。与「在有序数组里找下标」不同：这里 `check` 往往是贪心或模拟。

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

### 最小生成树

- **Kruskal**：边排序 + 并查集，直到 n-1 条边；稀疏图常用。
- **Prim**：从任一点扩展，堆维护「已连通块到未访问点的最小边权」；稠密图或邻接表实现见 `algorithms/graph/mst/prim.*`。

### 滑动窗口

- 右扩满足条件，左缩维持/破坏条件；`deque` 或频次数组维护窗口性质。

### 单调栈 / 单调队列

- 栈底到栈顶单调增或单调减；新元素入栈时弹出不保持单调性的旧元素；常用于「下一个更大元素」、柱状图最大矩形、滑动窗口最值（单调队列）。

### Trie（前缀树）

- 边表示字符；从根沿边走即前缀；插入 / 前缀查询字符串长度 L 时一般为 O(L)（字母表大小为常数时）。

### KMP

- `next[i]`：模式串在位置 i 失配时模式应回退到的下标；主串指针不回退，整体 O(n+m)。

### Z 函数

- `z[i]` 为 `s[i:]` 与 `s` 的最长公共前缀长度；配合 `pat + sep + text` 可做线性模式匹配，见 `algorithms/string/z_algorithm.*`。

### Manacher

- 奇偶回文统一为 `#a#b#` 后中心扩展 + 镜像优化；最长回文子串 O(n)，见 `algorithms/string/manacher.*`。

### AC 自动机（Aho–Corasick）

- Trie 上建 **fail** 指针（BFS，类 KMP）；扫描主串 O(n)；多模式匹配见 `algorithms/string/ac_automaton.*`。

### 双指针

- **对撞**：左右端向中间移动，常用于有序数组求和、去重、接雨水变体。
- **快慢**：链表判环、找中点；数组原地重排（如移动零）。

### 前缀和与差分

- **前缀和**：`s[i]=sum(a[0..i-1])`，区间和 O(1)；二维同理。
- **差分**：对区间 `[l,r)` 加常数在 `d[l]+=v, d[r]-=v`，最后前缀还原；树上前缀可用「链上差分 + LCA」思路（本仓库进阶题单再补）。

### 贪心

- 局部最优推全局：常见证法有**交换论证**（任意最优解经有限次交换不劣于贪心构造）、**拟阵**（了解即可）。
- 实现前先想清楚反例；面试口述「为何贪心成立」往往比代码更关键。

### 动态规划（通用）

- **状态**：用最少变量描述子问题边界（下标、容量、 bitmask 等）。
- **转移**：显式写出「从哪些更小状态来」；注意遍历顺序（0-1 背包一维数组需倒序）。
- **边界与答案**：`dp[0]`、空串、空集；答案可能是 `max(dp)` 或 `dp[n][·]` 的某一维投影。
- **空间**：观察是否只需上一行 → **滚动数组**。

### 拓扑排序

- DAG 上 Kahn（入度队列）或 DFS 后序染色；有环则无法排出全序。

### 网络流

- **Edmonds–Karp**：BFS 找增广路；`s==t` 时流量为 0；实现见 `algorithms/graph/network_flow/edmonds_karp.*`。

### 最短路（补充）

- **Bellman–Ford**：松弛 n-1 轮；第 n 轮仍可松弛则从源点可达负环；实现见 `algorithms/graph/shortest_path/bellman_ford.*`（**SPFA** 为其队列优化，最坏仍需谨慎）。
- **Floyd–Warshall**：三重循环中转点 k；全源 O(V³)；`dist[i][i]<0` 判负环；实现见 `algorithms/graph/shortest_path/floyd_warshall.*`。

### 莫队

- 离线重排区间询问，配合 `add(i)` / `remove(i)` 维护区间信息；指针在数组上移动总距离约 O((n+q)·√n) 量级；实现见 `algorithms/advanced/mo_algorithm/`。

### 树上 LCA

- **倍增**：DFS 求深度与 `up[k][u]`（2^k 祖先），每次查询 O(log n)；实现见 `algorithms/graph/lca/`。另可学 Tarjan 离线、欧拉序 + RMQ。

### 二分图匹配

- **最大匹配（Kuhn）**：从左部点 DFS 找增广路，反复匹配直到无法再增广；O(V·E)；实现见 `algorithms/graph/bipartite_matching/` 的 `kuhn_max_matching`。
- **最小费用完美匹配（匈牙利 KM）**：n×n 费用矩阵，对偶变量 + 增广；O(n³)；同目录 `hungarian_min_cost`。
- **Hopcroft–Karp** 为 O(√V·E) 的最大匹配写法，大规模图可在此基础上扩展 BFS 分层。

### 快速幂

- 二进制拆分指数：底数反复平方，指数右移；模幂全程 `% mod`；实现见 `algorithms/math/fast_power/`。

### 扩展欧几里得

- 递归或迭代求 `(g,x,y)` 使 `ax+by=gcd(a,b)`；互素时可得模逆；解 `ax≡b (mod m)` 见 `algorithms/math/extended_gcd/`。

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
| 并查集 `find`/`union`（路径压缩 + 按秩） | 均摊 α(n)† | 同上 | O(n) |
| 线段树 / 树状数组 单点或区间 | O(log n) | O(log n) | O(n) |
| Trie 插入 / 前缀查询 | O(L) | O(L) | 结点数 |
| KMP / Z / Manacher / AC（串长 n，模式总长 m） | O(n+m) / O(n) / O(n) / O(n+m+输出) | 同上 | O(字母表·状态数) |
| DFS/BFS（图） | O(V+E) | O(V+E) | O(V) |
| Dijkstra（堆） | O((V+E) log V) | 同上 | O(V) |
| Prim MST（堆） | O((V+E) log V) | 同上 | O(V) |
| Kruskal MST | O(E log E) | O(E log E) | O(V) |
| Bellman–Ford（单源） | O(V·E) | O(V·E) | O(V) |
| Floyd–Warshall（全源） | O(V^3) | O(V^3) | O(V^2) |
| Edmonds–Karp（最大流） | O(V·E^2) | O(V·E^2) | O(V^2) |
| 稀疏表 RMQ（静态区间最值） | O(n log n) 预处理 | O(1) 查询 | O(n log n) |
| 滚动哈希 + 二分 / 双哈希 | O(n) 预处理 | 单次比较 O(1)~O(log n) | O(n) |
| 莫队（显式 add/remove） | O((n+q)·√n) 量级* | 同上 | O(值域) |
| 树上 LCA（倍增） | O(n log n) 预处理 | O(log n) 单次查询 | O(n log n) |
| 二分图最大匹配（Kuhn） | O(V·E) | O(V·E) | O(V) |
| 匈牙利 KM（n×n 完美匹配） | O(n³) | O(n³) | O(n²) |
| 快速幂 / 模幂 | O(log e) | O(log e) | O(1) |
| 扩展欧几里得 / 模逆 | O(log min(a,b)) | O(log min(a,b)) | O(1) |

\* 与块大小选取有关，常写作均摊 O((n+q)√n)。  
† α 为反阿克曼函数，实际可视为很小的常数级。

### 分析习惯

- 数清 **DP 状态规模**、**回溯分支因子**、**单调栈摊还**。
- 空间勿忘 **递归栈** 与 **辅助结构**。
- 写 **`assert` / 自测**时：建议 `#include <alg_std.hpp>` 后仍显式 `#include <cassert>`；`assert(含逗号的初始化列表)` 易被宏拆开，宜先赋给临时变量再断言（见 **[cpp-toolchain.md](cpp-toolchain.md)**、**[scripts/doc-scripts.md](../scripts/doc-scripts.md)**）。

### 边界与反例（专题维护清单）

每个 `algorithms/` / `data_structures/` 入口建议在 `notes.md` 或 `__main__` 中覆盖：

| 类别 | 建议覆盖 | 典型反例 |
|------|----------|----------|
| 图最短路 | 单点、非连通、`inf` 距离 | Dijkstra 遇负权边（应拒绝或换 Bellman–Ford） |
| MST | `n≤1`、非连通图 | 无边两顶点图不能静默返回 `0` |
| 网络流 | `s==t`、零容量、不连通 | `s==t` 增广路径长度为 0 |
| 拓扑 | 有向环、单点 | 环时返回 `None` |
| 字符串 | 空串、模式未命中 | AC 空模式需显式拒绝 |
| 模运算 | `mod==1`、`e==0` | `mod==1` 时模幂结果为 `0`（非数学意义上的 `1`） |
| 组合 / 矩阵 | `k>n`、`n>max_n`、空矩阵 | 越界查询应返回 `0` 或 `ValueError` |
| DP | `n=0/1`、非法参数 | 数位 DP `k≤0`；矩阵链 `len(p)≤1` |
| 贪心 | 空输入、分数背包 `w≤0` | 0-1 背包用分数贪心会错 |
| 数据结构 | 空结构 pop、删不存在键 | 堆/BST/栈空操作应 `IndexError`/`KeyError` |

抽查后已加固的入口见各目录 `__main__`；新增专题请按上表补断言。

---

## Problem notes template

复制到新题目目录，保存为 **`notes.md`** 后填空。

### 题面

- **来源**：（如 LeetCode 1）
- **链接**：
- **难度 / 标签**：（可选，便于检索）
- **简述**：

### 思路

1. 解法一：
2. 解法二（可选）：

### 复杂度

| 解法 | 时间 | 空间 |
|------|------|------|
| | | |

### 自测与边界

- 样例、小规模手造、极端（空、单点、全相同、上限）；（C++/Python）末尾 `main` / `if __name__ == "__main__"` 断言习惯与仓库其他题一致。

### 陷阱与注意

-

### 相关题目

-
