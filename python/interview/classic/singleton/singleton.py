"""Python 单例的 4 种线程安全写法。"""

from __future__ import annotations

import threading
from typing import Any


def singleton_decorator(cls):
    """装饰器版：双检锁。"""

    instances: dict[type, Any] = {}
    lock = threading.Lock()

    def get_instance(*args: Any, **kwargs: Any) -> Any:
        if cls not in instances:
            with lock:
                if cls not in instances:
                    instances[cls] = cls(*args, **kwargs)
        return instances[cls]

    return get_instance


@singleton_decorator
class _Config:
    def __init__(self, name: str = "default") -> None:
        self.name = name


class SingletonMeta(type):
    """元类版：每个使用此元类的子类各自单例。"""

    _instances: dict[type, Any] = {}
    _lock = threading.Lock()

    def __call__(cls, *args: Any, **kwargs: Any) -> Any:
        if cls not in cls._instances:
            with cls._lock:
                if cls not in cls._instances:
                    cls._instances[cls] = super().__call__(*args, **kwargs)
        return cls._instances[cls]


class Logger(metaclass=SingletonMeta):
    def __init__(self, level: str = "INFO") -> None:
        self.level = level


class SingletonNew:
    """重写 __new__ 版（注意子类共享同一实例）。"""

    _instance: "SingletonNew | None" = None
    _lock = threading.Lock()

    def __new__(cls, *args: Any, **kwargs: Any) -> "SingletonNew":
        if cls._instance is None:
            with cls._lock:
                if cls._instance is None:
                    cls._instance = super().__new__(cls)
        return cls._instance


def _smoke() -> None:
    a = _Config(name="a")
    b = _Config(name="b")
    assert a is b
    assert a.name == "a"

    l1 = Logger("INFO")
    l2 = Logger("DEBUG")
    assert l1 is l2
    assert l1.level == "INFO"

    s1 = SingletonNew()
    s2 = SingletonNew()
    assert s1 is s2

    # 多线程并发构造仅产生一个实例
    holder: list[Logger] = []
    lock = threading.Lock()

    def worker() -> None:
        x = Logger()
        with lock:
            holder.append(x)

    ts = [threading.Thread(target=worker) for _ in range(32)]
    for t in ts:
        t.start()
    for t in ts:
        t.join()
    assert all(x is holder[0] for x in holder)

    print("singleton OK")


if __name__ == "__main__":
    _smoke()
