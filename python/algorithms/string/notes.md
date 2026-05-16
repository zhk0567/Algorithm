# 字符串算法（String）

| 文件 | 算法 |
|------|------|
| `string_algorithms.py` | KMP（LPS + 匹配） |
| `z_algorithm.py` | Z 函数 + 基于 `pat\\0text` 的模式匹配 |
| `manacher.py` | Manacher 最长回文子串 |
| `ac_automaton.py` | Aho–Corasick 多模式匹配 |

## 复杂度

| 算法 | 时间 |
|------|------|
| KMP | O(n+m) |
| Z 函数 | O(n) |
| Manacher | O(n) |
| AC 自动机 | O(n + 总模式长 + 命中数) |

## 边界

- **空模式 `pat==""`**：Python 版 KMP/Z 返回 `0..len(text)` 共 `len(text)+1` 个位置；C++ 版 `kmp_search` 在 `pat.empty()` 时返回**空列表**（跨语言对照时注意）。
- **Manacher**：`s==""` 返回 `""`。
- **AC 自动机**：不支持空模式串（`add("")` 抛错）。

与 `data_structures/tree/trie` 可对照前缀结构。

## 与 C++

见 [同构目录](../../../cpp/algorithms/string/)。
