# 任务清单

> **项目第一目标**：把常见算法与数据结构 **成体系、双语言、可运行自测** 地整理进本仓库（`algorithms/` + `data_structures/`），并与刷题归档、面试专题形成闭环。  

> **维护**：本文件**只列未完成项**（`[ ]`）；已完成内容见 [仓库手册](doc-handbook.md) 与各目录 `notes.md`。完成某条后**直接删除该行**。

---

## P1 目标（刷题与面试配套）

**要做到什么**：任何人从 `algorithms/` / `data_structures/` 某一专题出发，都能在仓库内**点开一道对应的 LeetCode 双语言题解**；剑指 / CodeTop 只做**索引表**、不重复造轮子；高频题单**版本固定**、可脚本校验；`interview/classic/` 每专题能**直接用于面试复述**。

**完成标准（全部满足即 P1 收口）**：

| 指标 | 基线（当前） | 目标 |
|------|----------------|------|
| `problems/leetcode/` 题量 | **119**（阶段 C 已完成；Hot 100 + **19** 道专题补缺） | **119**（阶段 B 网络流不占题号，与规划 120 差 1） |
| `algorithms/notes` 刷题索引 | 部分专题无例题链 | **每行有链**或写明「无 LeetCode 标配」（仅允许莫队、网络流等） |
| `data_structures/notes` 刷题索引 | 线段树/树状数组等偏空 | 链表随机指针、Trie 等有代表题 |
| `interview/top_frequent/` | **冻结 v1（103）**（阶段 E 已完成） | 扩题须先改本表并升级 `EXPECTED_SLUG_COUNT` |
| `problems/offer/`、`codetop/` | **30+30** 行索引（阶段 D 已完成） | 各 **30 行**映射（≥90% 链到已有 `leetcode/`） |
| `interview/classic/` | **14** 份 `notes.md` 含「面试要点」（阶段 F 已完成） | 同上 |

**原则**：不为刷数量重复建题；新题只补「专题无例题」；每阶段做完跑 `run_all_python.ps1` / `smoke_compile_cpp.ps1` / `check_top_frequent_leetcode.py`。

---

算法模板、复杂度、脚本回归命令见 **[doc-handbook.md](doc-handbook.md)**、**[scripts/doc-scripts.md](../scripts/doc-scripts.md)**。

**P0 主线**（`algorithms/` + `data_structures/` 双语言覆盖、边界自测）已落地，见 [algorithm-coverage.md](algorithm-coverage.md)。

**P2 工具链**（`alg_std.hpp`、MSVC 冒烟参数）已落地，见 [cpp-toolchain.md](cpp-toolchain.md)。

**P1 配套**（阶段 A–F：专题题解、offer/codetop 索引、top_frequent v1、classic 面试要点）已落地；`doc-tasks.md` 无剩余 `[ ]` 项时可视为 P1 收口。
