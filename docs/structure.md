# 仓库目录说明

> 约定：**`python/` 与 `cpp/` 同构**，便于双语言对照；根目录只放仓库级元数据，**不在根目录堆题目或临时文件**。

## 顶层一览

```
Algorithm/
├── GUIDE.md              # 仓库入口与快速导航
├── .gitignore
├── docs/                  # 语言无关：规范、路线图、任务、本说明
├── scripts/               # 维护用脚本（如 Hot 100 索引生成）
├── python/                # Python：数据结构 / 算法 / 刷题 / 面试
└── cpp/                   # C++：与 python/ 镜像
```

## `python/` 与 `cpp/` 子树（同构）

| 子目录 | 用途 |
|--------|------|
| `data_structures/` | 基础与进阶数据结构（每专题 README + 示例代码） |
| `algorithms/` | 按范式与专题组织的算法示例 |
| `problems/` | 刷题归档：`leetcode/`、`hot100/` 索引、`offer/`、`codetop/` 等 |
| `interview/` | 面试专题：`classic/`（手写 LRU 等）、`top_frequent/`（高频表链回 leetcode） |

各语言根说明：[python/GUIDE.md](../python/GUIDE.md)、[cpp/GUIDE.md](../cpp/GUIDE.md)。

## 题目目录命名（LeetCode 等）

- 目录名：`<4位编号>_<snake_case_英文标题>/`
- 例如：`0001_two_sum/`
- 内容：`GUIDE.md` + `solution.py` 或 `solution.cpp`（末尾自测）；SQL 题为 `solution.sql`

规范细节见 [problem_template.md](problem_template.md)。

## `scripts/`

| 文件 | 说明 |
|------|------|
| [gen_hot100_readme.py](../scripts/gen_hot100_readme.py) | 根据内置题单与实现映射，生成 `python/problems/hot100/GUIDE.md` 与 `cpp/problems/hot100/GUIDE.md` |

运行（在仓库根目录）：

```powershell
Set-Location F:\Study\Algorithm
python scripts\gen_hot100_readme.py
```

详见 [scripts/GUIDE.md](../scripts/GUIDE.md)。

## 文档索引（`docs/`）

总入口：[GUIDE.md](GUIDE.md)。

| 文件 | 说明 |
|------|------|
| [roadmap.md](roadmap.md) | 学习路线 |
| [next_tasks.md](next_tasks.md) | 后续任务与勾选进度 |
| [problem_template.md](problem_template.md) | 单题 README 模板 |
| [templates.md](templates.md)、[complexity.md](complexity.md) | 模板与复杂度速查（按需扩充） |

## 本地构建产物

编译产生的 `*.exe`、`*.o` 等已由根目录 [.gitignore](../.gitignore) 忽略；请勿将编译输出提交进仓库。
