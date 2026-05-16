# 项目收口总清单（可执行 · 可验证）

> **用途**：在宣布「本仓库阶段性封版」前，按章节**自上而下**逐项勾选；每一项应能回答「如何证明已完成」（命令输出、文件存在、人工签字等）。  
> **原则**：能脚本化的写进 `scripts/`；不能自动化的保留为人工项。完成一章后，在本文把 `- [ ]` 改为 `- [x]`，或在 PR/笔记中引用提交哈希。  
> **与 [doc-tasks.md](doc-tasks.md) 的关系**：`doc-tasks.md` 保持**极简**（仅活跃缺口）；**本表为封版前总闸门**，可长期保留直至你主动删档。

---

## 〇、收口门禁（必须先过）

- [ ] 已阅读 [doc-handbook.md](doc-handbook.md) 与 [algorithm-coverage.md](algorithm-coverage.md)，确认无与你认知冲突的「已宣称但未实现」表述
- [ ] 已阅读 [doc-tasks.md](doc-tasks.md)，确认其中**无**你希望封版前仍开放的 `[ ]`（若有，应先迁回本表或先做完再删）
- [ ] 选定**封版标签名**（如 `archive-2026-05`）并写入本文档顶部日期与标签（下方留空：标签 `__________`，日期 `__________`）
- [ ] 在干净 clone 下跑通「一键回归」四件套并留存日志路径：`________________________________`
  - [ ] `python scripts/check_top_frequent_leetcode.py`
  - [ ] `powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_all_python.ps1 -IncludeLeetcode`
  - [ ] `powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1`
  - [ ] `powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1 -LinkEntry`
- [ ] （可选）`powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1 -Compiler msvc` 在 MSVC 环境下通过
- [ ] `git status` 无意外未提交的大文件（`*.exe`、`*.obj`、模型权重等）
- [ ] 全库搜索常见密钥模式无命中：`password=`、`api_key`、`AKIA`、`BEGIN RSA PRIVATE KEY` 等（人工 + `rg`）

---

## 一、根入口与对外说明

- [ ] [README.md](../README.md) 中「快速开始」命令在你本机路径下可原样复制执行
- [ ] README 中指向的 `docs/` 三件套链接无死链
- [ ] README 已提及 [cpp-toolchain.md](cpp-toolchain.md)（若读者无 `g++` 仅有 MSVC）
- [ ] README 已说明：`doc-tasks.md` **仅未完成**；**收口总清单**为本文件（可加一句）
- [ ] 根目录除 `README.md` 外**无**第二个「仓库级说明」抢入口（符合仓库约定）

---

## 二、手册与总表一致性

- [ ] [doc-handbook.md](doc-handbook.md)「当前进度」段与 `leetcode/` 实际题量一致（或写明「约」与统计日期）
- [ ] [doc-handbook.md](doc-handbook.md) 中单题模板节与 `problems/leetcode` 最新题一致（字段名、目录命名）
- [ ] [algorithm-coverage.md](algorithm-coverage.md) §一 / §二 与 `python/`、`cpp/` 树内真实文件一致（抽查 + 全文扫 `🔲`）
- [ ] [algorithm-coverage.md](algorithm-coverage.md) §三 缺口队列表述与 [doc-tasks.md](doc-tasks.md) 无矛盾
- [ ] [scripts/doc-scripts.md](../scripts/doc-scripts.md) 中列出的脚本路径、参数与脚本头注释一致
- [ ] [cpp-toolchain.md](cpp-toolchain.md) 与 `smoke_compile_cpp.ps1` 实际参数一致（`-Compiler`、`IncludeDir`）

---

## 三、Python · `algorithms/`（每入口 4 检：存在 / notes / 自测 / C++ 镜像）

> 对下列每个**入口 `.py`**，勾选四项：`文件存在` · `同目录 notes.md` · ``if __name__`` 可跑 · `cpp/...` 同路径 `.cpp` 存在。

### 3.1 根与子目录入口（按路径）

- [ ] `advanced/sqrt_decomposition.py` — 四检
- [ ] `advanced/mo_algorithm/mo_algorithm.py` — 四检
- [ ] `backtracking/backtracking.py` — 四检
- [ ] `bit_manipulation/bit_manipulation.py` — 四检
- [ ] `divide_and_conquer/divide_and_conquer.py` — 四检
- [ ] `dynamic_programming/bitmask/bitmask_dp.py` — 四检
- [ ] `dynamic_programming/digit/digit_dp.py` — 四检
- [ ] `dynamic_programming/interval/interval_dp.py` — 四检
- [ ] `dynamic_programming/knapsack/knapsack_dp.py` — 四检
- [ ] `dynamic_programming/linear/linear_dp.py` — 四检
- [ ] `dynamic_programming/tree/tree_dp.py` — 四检
- [ ] `graph/bipartite_matching/bipartite_matching.py` — 四检
- [ ] `graph/lca/lca.py` — 四检
- [ ] `graph/mst/kruskal.py` — 四检
- [ ] `graph/mst/prim.py` — 四检
- [ ] `graph/network_flow/edmonds_karp.py` — 四检
- [ ] `graph/scc/tarjan.py` — 四检
- [ ] `graph/shortest_path/bellman_ford.py` — 四检
- [ ] `graph/shortest_path/dijkstra.py` — 四检
- [ ] `graph/shortest_path/floyd_warshall.py` — 四检
- [ ] `graph/topological_sort/kahn.py` — 四检
- [ ] `graph/traversal/graph_traversal.py` — 四检
- [ ] `greedy/greedy.py` — 四检
- [ ] `math/combinatorics/combinatorics.py` — 四检
- [ ] `math/extended_gcd/extended_gcd.py` — 四检
- [ ] `math/fast_power/fast_power.py` — 四检
- [ ] `math/geometry/geometry.py` — 四检
- [ ] `math/matrix/matrix.py` — 四检
- [ ] `math/number_theory/number_theory.py` — 四检
- [ ] `math/probability/probability.py` — 四检
- [ ] `prefix_sum/prefix_sum.py` — 四检
- [ ] `recursion/recursion.py` — 四检
- [ ] `searching/searching.py` — 四检
- [ ] `sliding_window/sliding_window.py` — 四检
- [ ] `sorting/sorting.py` — 四检
- [ ] `string/ac_automaton.py` — 四检
- [ ] `string/manacher.py` — 四检
- [ ] `string/string_algorithms.py` — 四检
- [ ] `string/z_algorithm.py` — 四检
- [ ] `two_pointers/two_pointers.py` — 四检

### 3.2 `python/algorithms/notes.md` 刷题索引

- [ ] 表中每一行均有有效 `../problems/leetcode/...` 链或「无标配题」说明（莫队、网络流等）
- [ ] 与 [cpp/algorithms/notes.md](../cpp/algorithms/notes.md) 表结构、题号集合一致（允许表述差异，不允许死链单方存在）

---

## 四、Python · `data_structures/`（每入口 4 检）

- [ ] `advanced/bloom_filter/bloom_filter.py` — 四检
- [ ] `advanced/lru_cache/lru_cache.py` — 四检
- [ ] `advanced/skip_list/skip_list.py` — 四检
- [ ] `graph/adjacency_list/graph_list.py` — 四检
- [ ] `graph/adjacency_matrix/graph_matrix.py` — 四检
- [ ] `graph/disjoint_set/union_find.py` — 四检
- [ ] `linear/array/dynamic_array.py` — 四检
- [ ] `linear/deque/deque.py` — 四检
- [ ] `linear/hash_table/hash_table.py` — 四检
- [ ] `linear/linked_list/linked_list.py` — 四检
- [ ] `linear/queue/queue.py` — 四检
- [ ] `linear/stack/stack.py` — 四检
- [ ] `tree/avl/avl.py` — 四检
- [ ] `tree/binary_tree/binary_tree.py` — 四检
- [ ] `tree/bst/bst.py` — 四检
- [ ] `tree/fenwick_tree/fenwick_tree.py` — 四检
- [ ] `tree/heap/heap.py` — 四检
- [ ] `tree/red_black_tree/red_black_tree.py` — 四检
- [ ] `tree/segment_tree/segment_tree.py` — 四检
- [ ] `tree/trie/trie.py` — 四检

### 4.1 `python/data_structures/notes.md`

- [ ] 「子目录 ↔ 刷题索引」表无死链、与当前 `leetcode/` 目录一致
- [ ] [cpp/data_structures/notes.md](../cpp/data_structures/notes.md) 与之同构（或明确写「C++ 表见 …」且链有效）

---

## 五、C++ 镜像与工具链

- [ ] 上述 §三、§四 中每个入口在 `cpp/` 下均有对应 `.cpp` 且 `#include <alg_std.hpp>`（或等价标准头），**无**残留 `bits/stdc++.h`
- [ ] `cpp/include/alg_std.hpp` 为当前唯一「胖头」策略；新增题解不得再引入 `bits/stdc++.h`
- [ ] 任意挑 5 个 `cpp/problems/leetcode/*/solution.cpp` 用 `g++ -std=c++17 -I cpp/include` 单文件编译通过
- [ ] `scripts/migrate_bits_stdc.ps1` 在空跑时输出 `0 .cpp`（证明无回潮）

---

## 六、`problems/leetcode/` 双语言题解

### 6.1 全量元数据（可脚本辅助）

- [ ] `python/problems/leetcode` 与 `cpp/problems/leetcode` **目录名**集合一致（`Compare-Object` 或自写脚本）
- [ ] 每个 slug 目录下**同时**存在：`solution.py`、`solution.cpp`、`notes.md`（Python 侧 `notes.md` 为详注；C++ 可为「见 Python」短注）
- [ ] 每个 `solution.py` / `solution.cpp` 含 `__main__` 或 `main()` 自测（与 `run_all_python` / 本地编译习惯一致）
- [ ] `python/problems/notes.md` 中归档题量数字与上一步计数一致
- [ ] SQL 题（若有）约定为 `solution.sql` 且 README/手册中已说明例外

### 6.2 题解质量（抽样 + 重点）

- [ ] 随机抽 **10** 题：题意、复杂度、`notes` 中「仓库专题」链有效（记录题号：____ ____ ____ …）
- [ ] 图论类题（最短路、MST、并查集、拓扑、二分图）**各至少 1 题**已人工复读 `notes` 无硬伤
- [ ] DP 类（线性、区间、背包、数位、状压、树形）**各至少 1 题**同上
- [ ] 易错模板（网络流 `s==t`、Dijkstra 负权、空模式 AC 等）在题解或专题 `notes` 中有边界提示

### 6.3 `hot100/`

- [ ] `python/scripts/gen_hot100_readme.py`（若仍使用）生成结果与 `leetcode/` 实际目录无死链
- [ ] `hot100/notes.md` 双语文首说明与维护命令仍正确

---

## 七、`problems/` 其他来源

- [ ] `python/problems/offer/notes.md`：**30** 行表完整、剑指独占行语义清晰
- [ ] `python/problems/codetop/notes.md`：**30** 行表完整、与 `leetcode/` 链一致
- [ ] `cpp/problems/offer`、`codetop` 与 Python 版交叉引用正确
- [ ] `nowcoder/`、`luogu/`：若无题解，手册中已写明「预留」或删除误导性「即将上线」表述

---

## 八、`interview/`

### 8.1 `top_frequent/`（v1 冻结）

- [ ] `EXPECTED_SLUG_COUNT` 与双语文首声明一致
- [ ] 扩题流程写清：先改 `doc-tasks` / 本表 → 再改表 → 再跑 `check_top_frequent_leetcode.py`

### 8.2 `classic/`（14 专题）

- [ ] 每个子目录 `notes.md` 含 **「面试要点」** 节（或 C++ 短注链回 Python 详述）
- [ ] 每个子目录 `notes.md` 含可复制的 **编译 / 运行** 命令（Python 或 C++ 至少一侧）
- [ ] 高并发示例在手册中已提醒「教学向、非生产压测结论」

---

## 九、脚本与维护工具

- [ ] `scripts/run_all_python.ps1` 默认根与 `-IncludeLeetcode` 行为与 [doc-scripts.md](../scripts/doc-scripts.md) 描述一致
- [ ] `scripts/smoke_compile_cpp.ps1` 默认 `-I cpp/include` 与可选 `-Compiler msvc` 已文档化
- [ ] `scripts/check_top_frequent_leetcode.py` 题量断言失败时错误信息可指导维护者下一步
- [ ] （可选）新增 `scripts/count_leetcode_dirs.ps1` 或 `Makefile` 目标 `regression` 一键调用四件套
- [ ] （可选）`pre-commit` / CI 配置：至少跑 `check_top_frequent` + `smoke_compile`（或子集）

---

## 十、Git 与发布 hygiene

- [ ] `.gitignore` 覆盖：`*.exe`、`*.obj`、`*.pyc`、`__pycache__/`、IDE 垃圾、大模型权重
- [ ] 无 LFS 误用导致 clone 体积失控（若用 LFS，README 说明）
- [ ] 打 tag 前：`git diff` 无意外大文件；`git log` 信息可读
- [ ] （可选）撰写 `CHANGELOG.md` 或 tag 附注：从「空仓库 → 当前」里程碑一条
- [ ] （可选）GitHub/GitLab **Release** 正文粘贴四件套回归摘要

---

## 十一、安全与许可

- [ ] 第三方代码（若有）LICENSE / 署名在 `NOTICE` 或各子目录 `notes.md` 已交代
- [ ] 外链（题面、论文、Rigtorp 队列等）可访问或注明镜像日期
- [ ] 无个人路径写死（如 `F:\Study\...`）进入**必须**提交的代码正文（文档示例可用占位符）

---

## 十二、知识债登记（封版后仍可做）

> 本节**不阻塞封版**；用于登记「已知不完美」以免遗忘。

- [ ] 记录：希望未来补的 LeetCode 题号列表（最多 20 行）：  
  `___________________________________________________________________________`
- [ ] 记录：希望升级为 `top_frequent` v2 的题号/理由：  
  `___________________________________________________________________________`
- [ ] 记录：希望替换为 MSVC 为主力时的迁移备注：  
  `___________________________________________________________________________`

---

## 十三、封版签字（预审）

> **说明**：宣布「完全封版」前，建议至少完成 **§〇～§十四**（含 LeetCode 机械验收 CSV 无缺失）。§十五～§二十五为**扩展闸**，可按精力分批勾选。

- [ ] 执行人：`__________` 日期：`__________`
- [ ] 复核人（可选）：`__________` 日期：`__________`
- [ ] 封版标签：`__________` 对应提交：`__________`

---

## 十四、LeetCode 全目录机械验收（建议脚本 + 人工兜底）

> 目标：对 `python/problems/leetcode/<slug>/` 与 `cpp/.../<slug>/` **每一对**完成下列固定动作（可用 PowerShell / Python 一次性循环；人工仅处理异常）。

- [ ] 已编写或已运行一次性脚本：输出「slug 列表 + py/cpp/notes 三文件齐否」CSV 路径：`________________`
- [ ] CSV 中 **缺失** / **单方存在** 的 slug 数为 **0**（若有，已在本节末尾「异常表」登记并修复）
- [ ] 对所有 `solution.py`：`rg "if __name__"` 计数 = 含 `__main__` 的文件数（或明确例外清单）
- [ ] 对所有 `solution.cpp`：存在 `int main` 或可链接的测试入口（与当前仓库约定一致）
- [ ] 对所有 `notes.md`：含 LeetCode 题链 `https://leetcode` 或 `leetcode.cn`（或注明「内网离线」例外）
- [ ] 随机 **20** 题：题号与 `slug` 中四位数字一致（防目录名手滑）
- [ ] 随机 **10** 题：`notes.md` 中「仓库专题」相对路径在仓库内存在
- [ ] 边界题（流、最短路、空串、图不连通）已在 `docs/doc-handbook.md` 或题 `notes` 中至少一处提及

### 14.1 异常登记（机械验收失败时填写）

| slug | 问题 | 修复提交 |
|------|------|----------|
| | | |
| | | |

---

## 十五、专题 `notes.md` 与 `GUIDE.md` 普查

- [ ] `python/algorithms/**/notes.md` 无断链至 `../problems/leetcode/`（抽样 **15** 个 + 全文 `rg` 可疑 `](..`）
- [ ] `cpp/algorithms/**/notes.md` 与上同构抽查 **10** 个
- [ ] `python/data_structures/**/notes.md` 抽查 **10** 个
- [ ] `cpp/data_structures/**/notes.md` 抽查 **10** 个
- [ ] 凡存在 `GUIDE.md` 的目录：与 `notes.md` 无互相矛盾命令（编译器、路径、`-I`）
- [ ] `python/problems/hot100/GUIDE.md`（若有）与 `notes.md` 索引策略一致

---

## 十六、`interview/classic` 十四专题深化（每专题 6 检）

> 对 `thread_pool`、`thread_safe_queue`、`ring_buffer`、`semaphore`、`rwlock`、`rwlock_writer_pref`、`singleton`、`rate_limiter`、`ticket_lock`、`tas_spinlock`、`lockfree_stack`、`mpmc_queue`、`lru_cache`、`lfu_cache` **各**勾选下列 6 项。

- [ ] **thread_pool**：6 检（README 链 / notes / py 自测 / cpp 编译运行 / 与 Executor 对照一句 / shutdown 语义说明）
- [ ] **thread_safe_queue**：6 检
- [ ] **ring_buffer**：6 检
- [ ] **semaphore**：6 检
- [ ] **rwlock**：6 检
- [ ] **rwlock_writer_pref**：6 检
- [ ] **singleton**：6 检
- [ ] **rate_limiter**：6 检
- [ ] **ticket_lock**：6 检
- [ ] **tas_spinlock**：6 检
- [ ] **lockfree_stack**：6 检
- [ ] **mpmc_queue**：6 检
- [ ] **lru_cache**：6 检
- [ ] **lfu_cache**：6 检

---

## 十七、图论模板专项（每算法 5 检）

> 对下列每个**算法入口**（py + cpp），五检：`复杂度在 notes` · `反例或边界在 notes 或 __main__` · `与 algorithm-coverage 状态一致` · `无已修 bug 回归遗漏` · `刷题索引表中有题或豁免说明`

- [ ] `graph/traversal` — 五检
- [ ] `graph/topological_sort/kahn` — 五检
- [ ] `graph/shortest_path/dijkstra` — 五检
- [ ] `graph/shortest_path/bellman_ford` — 五检
- [ ] `graph/shortest_path/floyd_warshall` — 五检
- [ ] `graph/mst/kruskal` — 五检
- [ ] `graph/mst/prim` — 五检
- [ ] `graph/scc/tarjan` — 五检
- [ ] `graph/network_flow/edmonds_karp` — 五检
- [ ] `graph/bipartite_matching` — 五检
- [ ] `graph/lca` — 五检

---

## 十八、动态规划模板专项（每范式 5 检）

- [ ] `linear_dp` — 五检
- [ ] `interval_dp` — 五检
- [ ] `knapsack_dp` — 五检
- [ ] `digit_dp` — 五检
- [ ] `bitmask_dp` — 五检
- [ ] `tree_dp` — 五检

---

## 十九、数学与字符串模板专项

- [ ] `number_theory` / `combinatorics` / `matrix` / `geometry` / `probability` / `fast_power` / `extended_gcd` — 各：notes 有复杂度 + `__main__` 覆盖至少 1 个非平凡样例
- [ ] `ac_automaton` / `manacher` / `z_algorithm` / `string_algorithms` — 各：空串 / 单字符边界在代码或 notes 中可查

---

## 二十、数据结构树与高级结构专项

- [ ] `segment_tree` 与 `fenwick_tree`：与题 **307** 索引互链已检查
- [ ] `red_black_tree` / `avl` / `bst`：插入删除复杂度表述与实现一致（人工快读）
- [ ] `bloom_filter`：假阳性说明在 notes
- [ ] `skip_list`：层数随机性与复杂度说明在 notes

---

## 二十一、代码风格与可维护性（全库轻量）

- [ ] Python：`ruff` / `flake8` / `pylint` 任选其一跑通且无「必须修」级告警（或登记豁免配置路径：`__________`）
- [ ] C++：`-Wall -Wextra` 冒烟下无新增 warning 被静默忽略（或登记 `-Wno-xxx` 理由）
- [ ] 无大范围 `TODO` / `FIXME` 未解释（`rg "FIXME|TODO"` 结果已审）
- [ ] 无被注释掉的大段死代码块（>50 行）未说明原因

---

## 二十二、性能与体量

- [ ] 全库体积（Windows）：在仓库根目录执行  
  `Get-ChildItem -Recurse -File -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum`  
  记录 `Sum`（字节）并换算为 `__________` MB/GB（可接受范围内）
- [ ] 最大单文件体积 `__________` MB（若超标，已拆分或移出 Git LFS）
- [ ] `run_all_python.ps1 -IncludeLeetcode` 总耗时 `__________` s（记录在案，便于以后 CI 超时设置）

---

## 二十三、离线可用性与可移植性

- [ ] 新机器仅装 Python 3.x + g++ 时，按 README 可在 **30** 分钟内跑通四件套（自测一次并记录卡点）
- [ ] 无硬编码本机用户名、盘符于**提交内容**（文档示例除外且已标注「示例路径」）
- [ ] 所有「请在本机修改」类说明集中在 `docs/`，子目录不散落冲突指引

---

## 二十四、归档与冻结策略（封版之后）

- [ ] 已决定：封版后 `main` 是否冻结为只读（或仅接受 typo / 链接修复）
- [ ] 已决定：新题进入 `dev` 分支还是新仓库；并写入 README 一句
- [ ] 若迁移至新仓库：本仓库 README 顶部「继任仓库」链接 `__________`
- [ ] 本文件 `project-closeout-checklist.md` 的最终存放位置已选定（根 `docs/` 或 `docs/archive/`）

---

## 二十五、最终「可宣布完成」声明（全部勾选后填写）

> 仅当 **§〇～§十四**（含 LeetCode 机械验收 CSV 无缺失）及你认可的 **§十五～§二十四** 子集全部满足后勾选。

- [ ] 我确认：本仓库当前状态满足我对「双语言、可自测、索引闭环」的个人标准
- [ ] 我确认：已知知识债已写入 **第十二节** 或独立 issue/笔记
- [ ] 我确认：回归日志与 tag 已保存，日后可复现

**声明人签名**：`________________` **日期**：`________________`

---

*文档版本：随仓库演进可增删章节；封版完成后可将本文移至 `docs/archive/` 并改 README 一句「封版快照见 …」。*
