# 最短路（C++）

| 文件 | 算法 |
|------|------|
| `dijkstra.cpp` | Dijkstra |
| `bellman_ford.cpp` | Bellman–Ford |
| `floyd_warshall.cpp` | Floyd–Warshall |

与 [Python 版](../../../../python/algorithms/graph/shortest_path/) 对照。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\algorithms\graph\shortest_path
g++ -std=c++17 -O2 -Wall -Wextra -o run_dijkstra.exe dijkstra.cpp
.\run_dijkstra.exe
g++ -std=c++17 -O2 -Wall -Wextra -o run_bf.exe bellman_ford.cpp
.\run_bf.exe
g++ -std=c++17 -O2 -Wall -Wextra -o run_floyd.exe floyd_warshall.cpp
.\run_floyd.exe
```
