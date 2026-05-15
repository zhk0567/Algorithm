# 维护脚本

规范、目录与单题模板见 **[../docs/doc-handbook.md](../docs/doc-handbook.md)**；**未完成待办**见 **[../docs/doc-tasks.md](../docs/doc-tasks.md)**；**算法/结构覆盖总表**见 **[../docs/algorithm-coverage.md](../docs/algorithm-coverage.md)**。

| 脚本 | 作用 |
|------|------|
| [gen_hot100_readme.py](gen_hot100_readme.py) | 生成 `python/problems/hot100/notes.md` 与 `cpp/problems/hot100/notes.md`（点赞序题单 + 实现目录链接） |
| [check_top_frequent_leetcode.py](check_top_frequent_leetcode.py) | 校验 `interview/top_frequent/notes.md`（py/cpp）：slug 集合一致、**103 题（v1 冻结）**、双语言 `leetcode/` 目录存在 |
| [run_all_python.ps1](run_all_python.ps1) | 白名单递归运行带 `__main__` 的 Python 自测（默认 `interview/classic`、`data_structures`、`algorithms`；加 `-IncludeLeetcode` 含 `problems/leetcode`） |
| [smoke_compile_cpp.ps1](smoke_compile_cpp.ps1) | 对 **`cpp/**` 下全部 `.cpp`** 做编译冒烟（默认 `g++ -c`，`-I cpp/include`；`-Compiler msvc` 可选；`-LinkEntry` 对专题入口链接运行） |
| [migrate_bits_stdc.ps1](migrate_bits_stdc.ps1) | 一次性将 `#include <bits/stdc++.h>` 换为 `#include <alg_std.hpp>`（P2 已执行，一般无需再跑） |

```powershell
Set-Location F:\Study\Algorithm
python scripts\gen_hot100_readme.py
python scripts\check_top_frequent_leetcode.py
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_all_python.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_all_python.ps1 -IncludeLeetcode
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1 -LinkEntry
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1 -Compiler msvc
```

修改题单或新增实现后，更新脚本内的 `IMPLEMENTED` 映射再运行即可。增删 `top_frequent/notes.md` 题链后运行 `check_top_frequent_leetcode.py` 防死链与双语文不同步。大改 C++/Python 自测后建议跑 `smoke_compile_cpp.ps1` / `run_all_python.ps1`。

**C++**：新代码用 `#include <alg_std.hpp>`（见 [docs/cpp-toolchain.md](../docs/cpp-toolchain.md)），编译加 `-I cpp/include`。`assert` 建议显式 `#include <cassert>`；避免 `assert(含逗号的 {…})` 被宏拆参，可先写入临时变量再断言。
