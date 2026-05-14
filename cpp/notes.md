# C++ 算法目录

与 `python/` **同构**。

- 仓库手册：[docs/doc-handbook.md](../docs/doc-handbook.md)
- 任务清单：[docs/doc-tasks.md](../docs/doc-tasks.md)
- 维护脚本：[scripts/doc-scripts.md](../scripts/doc-scripts.md)

单文件编译示例（在题目目录下）：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe solution.cpp
.\run.exe
```

多线程示例需加 `-pthread`。若环境无 `g++`，可使用 MinGW-w64 或 MSVC `cl`（需自行调整命令）。
