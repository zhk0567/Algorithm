# 树上最近公共祖先（LCA）

**倍增**：预处理每个结点向上 `2^k` 步的祖先，每次查询 O(log n)。

## 本目录

| 文件 | 说明 |
|------|------|
| `lca.py` | 无根树定根后 DFS 建表；`lca(u, v)` |

## 推荐题（本仓库）

- [LC 236 二叉树的最近公共祖先](../../../problems/leetcode/0236_lowest_common_ancestor_of_a_binary_tree/)（题面为二叉树指针版，思路与倍增/父链跳变一致，可作对照）

## 与 C++

见 [同构目录](../../../../cpp/algorithms/graph/lca/)。
