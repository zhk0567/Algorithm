// Prim 最小生成树（邻接表 + 小根堆）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int prim(int n, const vector<array<int, 3>>& edges) {
    if (n <= 1) return 0;
    vector<vector<pair<int, int>>> g(n);
    for (auto [u, v, w] : edges) {
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<char> vis(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);
    int tot = 0, taken = 0;
    while (!pq.empty() && taken < n) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        tot += w;
        ++taken;
        for (auto [v, wt] : g[u]) {
            if (!vis[v]) pq.emplace(wt, v);
        }
    }
    if (taken < n) throw runtime_error("graph is not connected");
    return tot;
}

int main() {
    vector<array<int, 3>> e{{0, 1, 4}, {1, 2, 3}, {0, 2, 2}};
    assert(prim(3, e) == 5);
    assert(prim(1, {}) == 0);
    try {
        prim(2, {});
        assert(false);
    } catch (const runtime_error&) {
    }
    cout << "prim OK" << endl;
    return 0;
}
