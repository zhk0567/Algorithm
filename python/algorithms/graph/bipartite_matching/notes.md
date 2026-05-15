# 二分图匹配（Bipartite Matching）

| 函数 | 说明 |
|------|------|
| `kuhn_max_matching` | 无向二分图**最大匹配**（DFS 增广路，常称 Kuhn / 「匈牙利」增广路写法） |
| `hungarian_min_cost` | **n×n 最小费用完美匹配**（经典匈牙利 KM，O(n³)） |

**Hopcroft–Karp** 为 O(√V·E) 的最大匹配算法，工程量大时可在此基础上扩展 BFS 分层 + 多路增广。

## 复杂度

| 算法 | 时间 |
|------|------|
| Kuhn 最大匹配 | O(V·E) |
| 匈牙利 KM | O(n³) |

## 与 C++

见 [同构目录](../../../../cpp/algorithms/graph/bipartite_matching/)。
