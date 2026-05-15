# 数论（Number Theory）

GCD、埃氏筛。**快速幂**见 [`fast_power/`](../fast_power/)，**扩展欧几里得 / 模逆**见 [`extended_gcd/`](../extended_gcd/)。

## 复杂度

欧几里得 O(log min(a,b))；埃氏筛 O(n log log n)。

## 边界

- `sieve(n)` 在 `n<2` 时返回长度 `n+1`、全为 `False` 的表（如 `sieve(0)==[False]`）。
