#include <bits/stdc++.h>
using namespace std;

optional<vector<int>> topological_sort(const vector<vector<int>>& adj) {
    int n = (int)adj.size();
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u]) ++indeg[v];
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (!indeg[i]) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indeg[v] == 0) q.push(v);
    }
    if ((int)order.size() != n) return nullopt;
    return order;
}

int main() {
    vector<vector<int>> g(3);
    g[0] = {1, 2};
    g[1] = {2};
    auto t = topological_sort(g);
    assert(t && *t == vector<int>({0, 1, 2}));
    cout << "topological_sort OK" << endl;
    return 0;
}
