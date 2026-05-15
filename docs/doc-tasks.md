# 任务清单

> **项目第一目标**：把常见算法与数据结构 **成体系、双语言、可运行自测** 地整理进本仓库（`algorithms/` + `data_structures/`），并与刷题归档、面试专题形成闭环。  
> **维护**：本文件**只列未完成项**（`[ ]`）；已完成内容见 [仓库手册](doc-handbook.md) 与各目录 `notes.md`。完成某条后**直接删除该行**。

---

## 主线（P0）：算法与数据结构全量整理

> **覆盖总表**（逐条状态 + 缺口队列）：**[algorithm-coverage.md](algorithm-coverage.md)** — 新增专题前先改表，落地后改 ✅。

- [ ] **`algorithms/`**：按 **[algorithm-coverage.md](algorithm-coverage.md)** 表 **§一** 维护 ✅、按 **§三** 补齐 **🔲**（子目录 `notes.md` + 双语言入口 + 自测）；对 ✅ 行抽查 **复杂度、边界、反例**
- [ ] **`data_structures/`**：按总表 **§二** 维护；**§三** 中属结构类的项优先落此树
- [ ] **跨域索引**：扩充 `python|cpp/algorithms/notes.md` 刷题映射，并与总表 **§四** 对齐
- [ ] **模板与复杂度文档**：每新增一类算法，同步 [doc-handbook.md](doc-handbook.md) 的 Algorithm templates / Complexity

---

## 配套（P1）：刷题与面试（在主线间隙推进）

- [ ] `problems/`：向 `leetcode/` 及 `offer/`、`nowcoder/`、`codetop/`、`luogu/` 等**持续加题**、补索引与交叉链接
- [ ] `interview/classic/`：按需扩展无锁/并发专题或加深笔记
- [ ] `interview/top_frequent/`：按个人题单扩表（非 Hot 100）

---

## 工具链（P2，可选）

- [ ] 对 **整个** `cpp/**`（含各题单目录）做**全量编译冒烟**（与现有 `scripts/smoke_compile_cpp.ps1` 白名单互补）
- [ ] 若长期只用 **MSVC**：规划去 `bits/stdc++.h` 或统一标准头

---

算法模板、复杂度、脚本回归命令见 **[doc-handbook.md](doc-handbook.md)**、**[scripts/doc-scripts.md](../scripts/doc-scripts.md)**。
