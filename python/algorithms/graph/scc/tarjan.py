"""Tarjan 强连通分量。"""

from __future__ import annotations


def tarjan_scc(adj: list[list[int]]) -> list[list[int]]:
    n = len(adj)
    dfn = [-1] * n
    low = [0] * n
    st: list[int] = []
    on = [False] * n
    time = 0
    comps: list[list[int]] = []

    def dfs(u: int) -> None:
        nonlocal time
        dfn[u] = low[u] = time
        time += 1
        st.append(u)
        on[u] = True
        for v in adj[u]:
            if dfn[v] == -1:
                dfs(v)
                low[u] = min(low[u], low[v])
            elif on[v]:
                low[u] = min(low[u], dfn[v])
        if low[u] == dfn[u]:
            comp: list[int] = []
            while True:
                x = st.pop()
                on[x] = False
                comp.append(x)
                if x == u:
                    break
            comps.append(comp)

    for i in range(n):
        if dfn[i] == -1:
            dfs(i)
    return comps


if __name__ == "__main__":
    # 0->1->2->0 与 2->3
    g = [[] for _ in range(4)]
    g[0].append(1)
    g[1].append(2)
    g[2].extend([0, 3])
    comps = tarjan_scc(g)
    assert len(comps) == 2
    print("scc OK")
