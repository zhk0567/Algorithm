# C++ 算法目录

与 `python/` **同构**。

- 仓库手册：[docs/doc-handbook.md](../docs/doc-handbook.md)
- 任务清单（仅未完成）：[docs/doc-tasks.md](../docs/doc-tasks.md)
- 维护脚本：[scripts/doc-scripts.md](../scripts/doc-scripts.md)

单文件编译示例（在题目目录下）：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -I cpp/include -o run.exe solution.cpp
.\run.exe
```

源码使用 `#include <alg_std.hpp>`（见 [docs/cpp-toolchain.md](../docs/cpp-toolchain.md)）。多线程示例需加 `-pthread`。亦可用 `.\scripts\smoke_compile_cpp.ps1` 全树冒烟。
