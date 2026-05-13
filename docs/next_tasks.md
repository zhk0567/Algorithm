# 后续任务清单

> 对照仓库骨架：`data_structures/` 第一阶段已铺完；以下按 **推荐推进顺序** 排列，可按个人节奏勾选。

---

## 环境与工程化（可选但省事）

- [ ] 本机安装 **MinGW-w64** 或 **LLVM**，将 `g++` / `clang++` 加入 `PATH`，在 `cpp/data_structures/**` 与各 `README` 命令下做一次全量编译冒烟
- [ ] 若长期只用 **MSVC**：为 `cpp/` 增加「无 `bits/stdc++.h`」的可选实现或统一改为标准头文件（工作量较大，单列里程碑）
- [ ] 在根 `README.md` 的「进度」区同步：数据结构已完成、算法/刷题完成度（避免与现状矛盾）

---

## 第二阶段：`algorithms/` 全目录填充（Python + C++ 同构）（已完成）

每个叶子目录已具备 `README.md` + 双语言示例（末尾自测），索引见 [python/algorithms/README.md](../python/algorithms/README.md)。

### 排序与查找

- [x] `algorithms/sorting/`、`algorithms/searching/`

### 基础范式

- [x] `algorithms/recursion/`、`divide_and_conquer/`、`greedy/`、`backtracking/`

### 双指针 / 窗口 / 前缀

- [x] `algorithms/two_pointers/`、`sliding_window/`、`prefix_sum/`

### 动态规划

- [x] `algorithms/dynamic_programming/` 下 `linear` / `interval` / `tree` / `digit` / `bitmask` / `knapsack`
- [ ] 子目录级「推荐题单链接」或题号索引（可选，刷题时补）

### 图论

- [x] `algorithms/graph/` 下 `traversal` / `shortest_path` / `mst` / `topological_sort` / `scc` / `network_flow`

### 字符串 / 数学 / 位运算 / 进阶

- [x] `algorithms/string/`（KMP）、`algorithms/math/` 各子目录、`bit_manipulation/`、`advanced/`（分块）
- [ ] 莫队、LCA 等扩展专题（按需再拆文件）

---

## 第三阶段：`problems/` 刷题归档（进行中）

- [x] 以 **LeetCode** 为主线：按 `000x_name/` 增量添加，`README.md` 对齐 [problem_template.md](problem_template.md) 结构
- [x] 维护 `problems/hot100/README.md` 索引表与 `leetcode/` 实题目录对应（当前 9 题索引，持续扩充）
- [x] `offer/`、`nowcoder/`、`codetop/`、`luogu/` 已写目录级 `README` 命名约定（子题待刷时添加）

---

## 第四阶段：`interview/`

- [ ] `interview/classic/`：手写 LRU（可与 `data_structures/advanced` 对照）、线程安全队列等专题
- [ ] `interview/top_frequent/`：高频表 + 链回 `problems/leetcode/`

---

## 文档与笔记

- [ ] 更新 [roadmap.md](roadmap.md)：标明「数据结构已完成」与下一阶段入口
- [ ] 扩充 [templates.md](templates.md)：从已实现的 DS/即将写的算法中抽取可粘贴模板
- [ ] [complexity.md](complexity.md)：按你已覆盖的算法补充一行一算法速查（可选）

---

## 质量与回归（随体量增长再做）

- [ ] 根目录增加 `scripts/run_all_python.ps1`（递归运行 `python/**/*.py` 中带 `if __name__` 的模块或白名单目录）
- [ ] 有 C++ 编译器后：对 `cpp/**/*.cpp` 做同样冒烟脚本

---

## 建议的「下一轮最小闭环」

完成下面 4 项即可形成稳定节奏，再批量扩展：

1. 更新根 `README.md` 进度描述  
2. `algorithms/sorting/` + `algorithms/searching/` 双语言各一套完整示例  
3. `algorithms/dynamic_programming/linear/` 先落 3～5 个经典模型（LIS、LCS、编辑距离等）  
4. `problems/leetcode/` 再追加 5～10 题，巩固目录与 README 模板  
