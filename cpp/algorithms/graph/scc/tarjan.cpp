#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tarjan_scc(const vector<vector<int>>& adj) {
    int n = (int)adj.size();
    vector<int> dfn(n, -1), low(n, 0), st;
    vector<char> on(n, 0);
    int timer = 0;
    vector<vector<int>> comps;
    function<void(int)> dfs = [&](int u) {
        dfn[u] = low[u] = timer++;
        st.push_back(u);
        on[u] = 1;
        for (int v : adj[u]) {
            if (dfn[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (on[v])
                low[u] = min(low[u], dfn[v]);
        }
        if (low[u] == dfn[u]) {
            vector<int> comp;
            while (true) {
                int x = st.back();
                st.pop_back();
                on[x] = 0;
                comp.push_back(x);
                if (x == u) break;
            }
            comps.push_back(comp);
        }
    };
    for (int i = 0; i < n; ++i)
        if (dfn[i] == -1) dfs(i);
    return comps;
}

int main() {
    vector<vector<int>> g(4);
    g[0] = {1};
    g[1] = {2};
    g[2] = {0, 3};
    auto comps = tarjan_scc(g);
    assert(comps.size() == 2u);
    cout << "scc OK" << endl;
    return 0;
}
