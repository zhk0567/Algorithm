# C++ 算法目录

与 `python/` **同构**。

- 仓库手册：[README](../README.md)
- 任务清单（仅未完成）：[README](../README.md#pending-tasks)

单文件编译示例（在题目目录下）：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -I cpp/include -o run.exe solution.cpp
.\run.exe
```

源码使用 `#include <alg_std.hpp>`（见 [README](../README.md#cpp-toolchain)）。多线程示例需加 `-pthread`。全树编译可在仓库根自行用 `g++ -c` 批处理或编辑器任务完成。
