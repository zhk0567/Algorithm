# Algorithm（算法整理）

本仓库用于系统整理 **Python** 与 **C++** 双语言算法与刷题记录，目录在两种语言下 **同构**，便于对照学习。

## 目录结构

| 路径 | 说明 |
|------|------|
| [docs/](docs/) | 路线图、任务、规范；**入口** [docs/README.md](docs/README.md) |
| [scripts/](scripts/) | 维护脚本（如 Hot 100 索引生成） |
| [python/](python/) | Python：`data_structures` / `algorithms` / `problems` / `interview` |
| [cpp/](cpp/) | C++：与 `python/` 同构 |

更细的树形说明见 **[docs/structure.md](docs/structure.md)**。

## 命名约定

- **LeetCode 等题目目录**：`<4位编号>_<snake_case_title>/`，例如 `0001_two_sum/`
- 每题目录内：`README.md`（题面、思路、复杂度、陷阱）+ `solution.py` 或 `solution.cpp`（文件末尾用 `main` / `if __name__` 跑简单样例）

## 快速导航

- [Python 数据结构](python/data_structures/README.md)
- [Python 算法分类](python/algorithms/README.md)
- [Python 刷题](python/problems/README.md)
- [Python 面试专题](python/interview/README.md)
- [C++ 说明与编译](cpp/README.md)
- [文档索引](docs/README.md)
- [学习路线图](docs/roadmap.md)
- [后续任务清单](docs/next_tasks.md)

## 进度（可手动更新）

- **数据结构**：第一阶段已完成（见 [docs/next_tasks.md](docs/next_tasks.md)）
- **算法分类**：第二阶段已完成（`python/algorithms/`、`cpp/algorithms/` 各叶子目录均有 README + 示例代码）
- **刷题**：LeetCode **Hot 100** 已对齐收录（99 题 Python+C++，LC 175 为 SQL-only；索引见 [python/problems/hot100/README.md](python/problems/hot100/README.md)）；`offer/`、`codetop/` 等见各子目录 README
- **面试专题**：第四阶段首批已完成（`interview/classic/`、`interview/top_frequent/`）

## 范例

- [LeetCode 1 两数之和（Python）](python/problems/leetcode/0001_two_sum/)
- [LeetCode 1 两数之和（C++）](cpp/problems/leetcode/0001_two_sum/)
