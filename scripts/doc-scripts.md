# 维护脚本

规范、目录与单题模板见 **[../docs/doc-handbook.md](../docs/doc-handbook.md)**；勾选待办见 **[../docs/doc-tasks.md](../docs/doc-tasks.md)**。

| 脚本 | 作用 |
|------|------|
| [gen_hot100_readme.py](gen_hot100_readme.py) | 生成 `python/problems/hot100/notes.md` 与 `cpp/problems/hot100/notes.md`（点赞序题单 + 实现目录链接） |
| [check_top_frequent_leetcode.py](check_top_frequent_leetcode.py) | 校验 `interview/top_frequent/notes.md`（py/cpp）中 `../../problems/leetcode/<slug>/` 链接：slug 集合一致、目录在双语言 `leetcode/` 下均存在 |
| [run_all_python.ps1](run_all_python.ps1) | 白名单递归运行带 `__main__` 的 Python 自测（默认 `interview/classic`、`data_structures`、`algorithms`；加 `-IncludeLeetcode` 含 `problems/leetcode`） |
| [smoke_compile_cpp.ps1](smoke_compile_cpp.ps1) | 对 `cpp/interview/classic`、`data_structures`、`algorithms`、`problems/leetcode` 下全部 `.cpp` 做 `g++ -c` 编译冒烟 |

```powershell
Set-Location F:\Study\Algorithm
python scripts\gen_hot100_readme.py
python scripts\check_top_frequent_leetcode.py
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_all_python.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_all_python.ps1 -IncludeLeetcode
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_compile_cpp.ps1
```

修改题单或新增实现后，更新脚本内的 `IMPLEMENTED` 映射再运行即可。增删 `top_frequent/notes.md` 题链后运行 `check_top_frequent_leetcode.py` 防死链与双语文不同步。大改 C++/Python 自测后建议跑 `smoke_compile_cpp.ps1` / `run_all_python.ps1`。
