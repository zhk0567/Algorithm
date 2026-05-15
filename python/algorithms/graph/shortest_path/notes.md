# 最短路（Shortest Path）

| 文件 | 算法 | 说明 |
|------|------|------|
| `dijkstra.py` | Dijkstra（堆） | 非负权单源 |
| `bellman_ford.py` | Bellman–Ford | 可有负权单源；第 n 轮仍可松弛则判负环 |
| `floyd_warshall.py` | Floyd–Warshall | 全源；`dist[i][i]<0` 判负环 |

**SPFA** 为 Bellman–Ford 的队列优化，本仓库以标准 BF 为准。

## 复杂度

- Dijkstra（堆）：O((V+E) log V)
- Bellman–Ford：O(V·E)
- Floyd–Warshall：O(V³)

## 与 C++

见 [同构目录](../../../../cpp/algorithms/graph/shortest_path/)。
