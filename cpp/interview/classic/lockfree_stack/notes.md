# Treiber 无锁栈（C++）

与 [Python 参考实现](../../../python/interview/classic/lockfree_stack/)（`treiber_ref.py`，带锁）对照阅读。

> **面试要点**：见 [Python 版 notes.md](../../../python/interview/classic/lockfree_stack/notes.md)。

## 编译运行

```powershell
Set-Location F:\Study\Algorithm\cpp\interview\classic\lockfree_stack
g++ -std=c++17 -O2 -Wall -Wextra -pthread -o run.exe treiber_stack.cpp
.\run.exe
```

## 注意

- **ABA**：本题为最小教学代码，未做 hazard pointer / epoch；面试需能说出风险与工程对策。
