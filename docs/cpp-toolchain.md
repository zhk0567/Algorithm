# C++ 工具链（P2）

本仓库 C++ 源码**不再依赖** GCC 专有的 `<bits/stdc++.h>`，统一通过 [`cpp/include/alg_std.hpp`](../cpp/include/alg_std.hpp) 引入常用标准库头，便于 **MSVC** 与 **MinGW g++** 共用同一套源码。

## 新文件 / 新题解

```cpp
#include <alg_std.hpp>
#include <cassert>  // 若写 assert 自测，建议保留（alg_std 已含，显式写更清晰）
using namespace std;
```

编译时加上 include 路径（脚本已默认处理）：

```text
-I cpp/include
```

## 回归

```powershell
Set-Location F:\Study\Algorithm
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1 -LinkEntry
```

可选 MSVC 冒烟（需已安装 Visual Studio 且 `cl` 在 PATH，或先运行 `vcvars64.bat`）：

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1 -Compiler msvc
```

## 编译器对照

| 项 | MinGW g++（默认） | MSVC `cl` |
|----|-------------------|-----------|
| 标准 | `-std=c++17` | `/std:c++17` |
| Include | `-I cpp/include` | `/I cpp\include` |
| 多线程 | `-pthread` | 默认支持；链接时一般无需额外开关 |
| 单文件编译 | `g++ -c ...` | `cl /c /EHsc ...` |

## assert 自测注意

- `assert(表达式含逗号的初始化列表)` 会被宏按逗号拆参，应先赋给临时变量再断言。
- 详见 [doc-handbook.md](doc-handbook.md) 与 [scripts/doc-scripts.md](../scripts/doc-scripts.md)。

## 历史迁移

一次性将 `#include <bits/stdc++.h>` 替换为 `#include <alg_std.hpp>`：

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\migrate_bits_stdc.ps1
```
