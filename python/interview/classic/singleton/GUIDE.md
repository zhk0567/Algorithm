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
