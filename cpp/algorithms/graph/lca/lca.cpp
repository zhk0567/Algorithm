// 树上倍增 LCA（与 Python 版同构）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct BinaryLiftingLCA {
    int n, LOG;
    vector<vector<int>> g, up;
    vector<int> dep;

    BinaryLiftingLCA(int n_, const vector<pair<int, int>>& edges, int root = 0) : n(n_) {
        LOG = 1;
        while ((1 << LOG) <= n) ++LOG;
        g.assign(n, {});
        for (auto [u, v] : edges) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dep.assign(n, 0);
        up.assign(LOG, vector<int>(n, -1));
        function<void(int, int)> dfs = [&](int u, int p) {
            up[0][u] = p;
            for (int k = 1; k < LOG; ++k) {
                int mid = up[k - 1][u];
                up[k][u] = (mid == -1 ? -1 : up[k - 1][mid]);
            }
            for (int v : g[u]) {
                if (v == p) continue;
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        };
        dfs(root, -1);
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[u] - dep[v];
        for (int k = 0; k < LOG; ++k)
            if (d >> k & 1) u = up[k][u];
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    }
};

int main() {
    int n = 5;
    vector<pair<int, int>> ed{{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    BinaryLiftingLCA t(n, ed, 0);
    assert(t.lca(3, 4) == 2);
    assert(t.lca(1, 3) == 0);
    assert(t.lca(1, 2) == 0);
    assert(t.lca(0, 4) == 0);
    cout << "lca OK" << endl;
    return 0;
}
