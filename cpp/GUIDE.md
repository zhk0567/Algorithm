# C++ 算法目录

与 `python/` **同构**。

- 仓库级目录说明：[docs/doc-handbook.md#repo-layout](../docs/doc-handbook.md#repo-layout)
- 维护脚本：[scripts/GUIDE.md](../scripts/GUIDE.md)

单文件编译示例（在题目目录下）：

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -I cpp/include -o run.exe solution.cpp
.\run.exe
```

使用 `#include <alg_std.hpp>`，详见 [docs/cpp-toolchain.md](../docs/cpp-toolchain.md)。多线程示例需加 `-pthread`。
