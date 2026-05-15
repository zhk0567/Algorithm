# 最小生成树（MST）

| 文件 | 算法 | 适用 |
|------|------|------|
| `kruskal.py` | Kruskal + 并查集 | 稀疏图，边表直接排序 |
| `prim.py` | Prim + 堆 | 稠密图或邻接表扩展方便 |

## 复杂度

- Kruskal：O(E log E)
- Prim（二叉堆）：O((V+E) log V)

## 边界

- `n≤1`：边权和为 `0`。
- **图须连通**；非连通时 `prim` / `kruskal` 抛出 `ValueError`（勿静默返回部分边权和）。

## 与 C++

见 [同构目录](../../../../cpp/algorithms/graph/mst/)。
