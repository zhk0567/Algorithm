# 快速幂（Fast Exponentiation）

| 函数 | 说明 |
|------|------|
| `fast_pow` | 整数幂 a^e（非模） |
| `mod_pow` | a^e mod mod（刷题常用） |

二进制把指数按位拆开，每步平方底数；模幂全程取模防溢出。

**复杂度**：O(log e)。

## 边界

- `mod==1` 时 `mod_pow` **恒返回 0**（含 `e=0`），与数学 `a^0=1` 不同，刷题按取模语义处理。

埃氏筛、GCD 等见 [`number_theory/`](../number_theory/)。

## 与 C++

[`cpp/algorithms/math/fast_power/`](../../../../cpp/algorithms/math/fast_power/)
