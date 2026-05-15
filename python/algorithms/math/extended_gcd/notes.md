# 扩展欧几里得（Extended GCD）

| 函数 | 说明 |
|------|------|
| `extgcd` | 返回 (g, x, y) 使 ax + by = g |
| `mod_inverse` | 互素时求模逆元 |
| `solve_linear_congruence` | 解 ax ≡ b (mod m)，返回 (最小非负解, 周期) |

**复杂度**：O(log min(a, b))。

## 与 C++

[`cpp/algorithms/math/extended_gcd/`](../../../../cpp/algorithms/math/extended_gcd/)
