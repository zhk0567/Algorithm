# Algorithm · 双语言算法与刷题仓库

面向 **面试准备** 与 **长期复习** 的个人知识库：**第一要务**是把 **算法与数据结构** 按专题 **双语言、可运行自测** 成体系整理（执行入口：**[doc-tasks.md](docs/doc-tasks.md)** P0 + **[algorithm-coverage.md](docs/algorithm-coverage.md)** 盘点表）。同一套目录在 **Python** 与 **C++** 下 **镜像同构**；并含 LeetCode 归档、手写面试专题等。

---

## 仓库约定（请先读）

| 约定 | 说明 |
|------|------|
| **唯一 `README.md`** | 全仓库只在**本根目录**保留 `README.md`；其余任何子目录的说明文件一律命名为 **`notes.md`**（Markdown）。 |
| **`docs/` 文档** | **[doc-handbook.md](docs/doc-handbook.md)**（目录·路线·模板）；**[doc-tasks.md](docs/doc-tasks.md)**（**仅未完成**；**P0=算法全量整理**）；**[algorithm-coverage.md](docs/algorithm-coverage.md)**（**覆盖盘点 + 缺口队列**）。 |
| **题目目录** | LeetCode 等：`python/problems/leetcode/<四位编号>_<snake_case>/` 与 `cpp/...` 对称；每题 **`notes.md` + `solution.py` / `solution.cpp`**（末尾自带简单断言或样例）；SQL 题为 `solution.sql`。 |
| **Hot 100 索引** | 点赞序题单表由脚本生成，见 `python/problems/hot100/notes.md` 与 `cpp/problems/hot100/notes.md`（与题号数值顺序无关）。 |

仓库说明、学习路线、算法骨架、复杂度与**单题写作模板**见 **[docs/doc-handbook.md](docs/doc-handbook.md)**；**未完成待办（P0）**见 **[docs/doc-tasks.md](docs/doc-tasks.md)**；**算法/数据结构覆盖总表**见 **[docs/algorithm-coverage.md](docs/algorithm-coverage.md)**。

---

## 顶层目录一览

```
Algorithm/
├── README.md          ← 你正在阅读的唯一仓库入口
├── docs/              ← [doc-handbook.md](docs/doc-handbook.md) + [doc-tasks.md](docs/doc-tasks.md) + [algorithm-coverage.md](docs/algorithm-coverage.md)
├── scripts/           ← 维护与回归（Hot100、top_frequent 校验、run_all_python、smoke_compile_cpp 等）
├── python/            ← Python：data_structures / algorithms / problems / interview
└── cpp/               ← C++：与 python/ 同构
```

---

## 快速开始

### Python

```powershell
Set-Location F:\Study\Algorithm
# 运行某一题（示例）
python python\problems\leetcode\0001_two_sum\solution.py
```

建议 **Python 3.10+**（广泛使用 `list[int]` 等内置泛型注解）。各子域入口：[python/notes.md](python/notes.md)。

### C++（MinGW / LLVM）

```powershell
Set-Location F:\Study\Algorithm\cpp\problems\leetcode\0001_two_sum
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe solution.cpp
.\run.exe
```

含 `std::thread` 的示例需加 **`-pthread`**。说明与习惯命令见 [cpp/notes.md](cpp/notes.md)。

### 维护脚本（索引 / 回归）

```powershell
Set-Location F:\Study\Algorithm
python scripts\gen_hot100_readme.py
python scripts\check_top_frequent_leetcode.py
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_all_python.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1
```

脚本说明：[scripts/doc-scripts.md](scripts/doc-scripts.md)。`run_all_python.ps1` 可加 `-IncludeLeetcode` 顺带跑全部 `leetcode` 的 `solution.py`（耗时更长）。

---

## 核心导航

| 你想… | 去哪里 |
|--------|--------|
| 看数据结构专题与代码 | [python/data_structures/notes.md](python/data_structures/notes.md) / [cpp/data_structures/notes.md](cpp/data_structures/notes.md) |
| 看算法分类（DP、图、字符串等） | [python/algorithms/notes.md](python/algorithms/notes.md) / [cpp/algorithms/notes.md](cpp/algorithms/notes.md) |
| 刷题归档与题源约定 | [python/problems/notes.md](python/problems/notes.md) / [cpp/problems/notes.md](cpp/problems/notes.md) |
| Hot 100 点赞序索引 | [python/problems/hot100/notes.md](python/problems/hot100/notes.md) |
| 手写专题（含 Treiber / Ticket Lock / 写者优先 RWLock / TAS / MPMC 无锁队列 等） | [python/interview/notes.md](python/interview/notes.md) |
| 覆盖盘点（P0） | [docs/algorithm-coverage.md](docs/algorithm-coverage.md) |
| 未完成待办 | [docs/doc-tasks.md](docs/doc-tasks.md) |
| 新题 `notes.md` 怎么写 | [docs/doc-handbook.md#problem-notes-template](docs/doc-handbook.md#problem-notes-template) |
| 学习路线 | [docs/doc-handbook.md#study-roadmap](docs/doc-handbook.md#study-roadmap) |

---

## 当前进度（摘要）

- **数据结构**：第一阶段已按专题铺全（双语言 + `notes.md`）。
- **算法**：第二阶段各子目录已有范式示例与说明。
- **LeetCode Hot 100**：已对齐收录（**99** 题 Python+C++，**LC 175** 为 SQL-only）；索引见上表 Hot 100 链接。
- **面试第四阶段**：`interview/classic/`（含 LRU、LFU、队列、单例、限流、环形缓冲、线程池、信号量、读写锁、**写者优先读写锁**、Treiber 栈、**Ticket Lock**、**TAS 自旋锁**、**MPMC 无锁队列** 等）与 `interview/top_frequent/`（双语文首含与 `leetcode/` 同步说明）。

详细**未完成**工程化待办见 **[docs/doc-tasks.md](docs/doc-tasks.md)**；**算法/结构覆盖与缺口队列**见 **[docs/algorithm-coverage.md](docs/algorithm-coverage.md)**。

---

## 新题入库流程（极简）

1. 在 `python/problems/leetcode/` 与 `cpp/problems/leetcode/` 下各建同名目录 `NNNN_snake_case/`。  
2. 复制 [docs/doc-handbook.md#problem-notes-template](docs/doc-handbook.md#problem-notes-template) 的结构到两边的 **`notes.md`**。  
3. 编写 `solution.py` / `solution.cpp`，末尾保留可本地运行的自检。  
4. 若该题属于 Hot 100：更新 `scripts/gen_hot100_readme.py` 中的 `IMPLEMENTED`，再运行脚本刷新 `hot100/notes.md`。

---

## 许可与声明

题目版权归 respective 平台（如 LeetCode）；本仓库代码与文字说明为个人学习整理，按你本地习惯决定是否开源协议；转载题目描述请注意平台条款。

若你发现某处仍残留旧链接或命名，欢迎直接改 **`notes.md`** 或 **[docs/doc-handbook.md](docs/doc-handbook.md)** 并提交修正。
