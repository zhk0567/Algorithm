#include <bits/stdc++.h>
using namespace std;

vector<int> dfs_order(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<char> seen(n, 0);
    vector<int> out;
    function<void(int)> dfs = [&](int u) {
        seen[u] = 1;
        out.push_back(u);
        for (int v : adj[u])
            if (!seen[v]) dfs(v);
    };
    dfs(start);
    return out;
}

vector<int> bfs_order(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<char> seen(n, 0);
    queue<int> q;
    q.push(start);
    seen[start] = 1;
    vector<int> out;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        out.push_back(u);
        for (int v : adj[u])
            if (!seen[v]) {
                seen[v] = 1;
                q.push(v);
            }
    }
    return out;
}

int main() {
    vector<vector<int>> adj(4);
    for (auto [u, v] : vector<pair<int, int>>{{0, 1}, {0, 2}, {1, 3}}) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    assert(dfs_order(adj, 0) == vector<int>({0, 1, 3, 2}));
    assert(bfs_order(adj, 0) == vector<int>({0, 1, 2, 3}));
    cout << "graph_traversal OK" << endl;
    return 0;
}
