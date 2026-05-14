# 字符串算法（String）

## 简介

模式匹配：KMP 线性时间；另有 Rabin-Karp、Manacher 等见扩展题单。

## KMP 复杂度

预处理 LPS O(m)，匹配 O(n+m)。

## 代码要点

`j` 回退用 `lps[j-1]`；与 `data_structures/tree/trie` 可对照前缀结构。
