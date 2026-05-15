# 字符串算法（C++）

| 文件 | 算法 |
|------|------|
| `string_algorithms.cpp` | KMP |
| `z_algorithm.cpp` | Z 函数 |
| `manacher.cpp` | Manacher |
| `ac_automaton.cpp` | Aho–Corasick |

与 [Python 版](../../../../python/algorithms/string/) 对照。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\algorithms\string
g++ -std=c++17 -O2 -Wall -Wextra -o run_kmp.exe string_algorithms.cpp
.\run_kmp.exe
g++ -std=c++17 -O2 -Wall -Wextra -o run_z.exe z_algorithm.cpp
.\run_z.exe
g++ -std=c++17 -O2 -Wall -Wextra -o run_manacher.exe manacher.cpp
.\run_manacher.exe
g++ -std=c++17 -O2 -Wall -Wextra -o run_ac.exe ac_automaton.cpp
.\run_ac.exe
```
