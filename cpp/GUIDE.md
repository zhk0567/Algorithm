# C++ 算法目录

与 `python/` **同构**。

- 仓库级目录说明：[docs/structure.md](../docs/structure.md)
- 维护脚本：[scripts/GUIDE.md](../scripts/GUIDE.md)

单文件编译示例（在题目目录下）：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -o run.exe solution.cpp
.\run.exe
```

多线程示例需加 `-pthread`。若环境无 `g++`，可使用 MinGW-w64 或 MSVC `cl`（需自行调整命令）。
