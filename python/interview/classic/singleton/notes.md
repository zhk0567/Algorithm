# 单例模式（Python）

> 给出 4 种线程安全的写法并相互对照。

| 方式 | 说明 |
|------|------|
| `singleton_decorator` | 装饰器 + `threading.Lock` 双检锁；最直观 |
| `SingletonMeta` | 元类；`__call__` 内加锁；子类化友好 |
| `SingletonNew` | 重写 `__new__`；继承时容易踩坑（共享同一实例） |
| `module_level` | 直接把全局变量 + 函数当作单例；最 Pythonic |

## 自测

```bash
python python\interview\classic\singleton\singleton.py
```

## 面试要点

- **适用场景**：全局配置、连接池门面、日志器（慎用，优先依赖注入）。
- **复杂度**：首次创建 O(1)；之后访问 O(1)。
- **标准库对照**：模块级单例最 Pythonic；`threading.Lock` 双检锁；元类/`__new__` 为面试口述模板。
- **常见坑**：双检锁未用 `volatile`/内存序（C++ 侧）；子类共享同一实例（`__new__` 版）；单测难以 mock。
