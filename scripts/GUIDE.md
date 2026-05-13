# 维护脚本

| 脚本 | 作用 |
|------|------|
| [gen_hot100_readme.py](gen_hot100_readme.py) | 生成 `python/problems/hot100/GUIDE.md` 与 `cpp/problems/hot100/GUIDE.md`（点赞序题单 + 实现目录链接） |

在仓库根目录执行：

```powershell
Set-Location F:\Study\Algorithm
python scripts\gen_hot100_readme.py
```

修改题单或新增实现后，更新脚本内的 `IMPLEMENTED` 映射再运行即可。
