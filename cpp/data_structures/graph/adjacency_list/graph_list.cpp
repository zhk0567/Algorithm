#include <alg_std.hpp>
#include <cassert>
using namespace std;

struct Graph {
    int n;
    bool directed;
    vector<vector<pair<int, int>>> adj;
    Graph(int n_, bool d = false) : n(n_), directed(d), adj(n_) {}

    void add_edge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        if (!directed) adj[v].push_back({u, w});
    }

    vector<int> dfs_order(int start) {
        vector<int> out;
        vector<bool> seen(n, false);
        function<void(int)> dfs = [&](int u) {
            seen[u] = true;
            out.push_back(u);
            for (auto [v, w] : adj[u])
                if (!seen[v]) dfs(v);
        };
        dfs(start);
        return out;
    }

    vector<int> bfs_order(int start) {
        vector<int> out;
        vector<bool> seen(n, false);
        queue<int> q;
        q.push(start);
        seen[start] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            out.push_back(u);
            for (auto [v, w] : adj[u])
                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
        }
        return out;
    }
};

int main() {
    Graph g(4, false);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    assert(g.dfs_order(0) == vector<int>({0, 1, 3, 2}));
    assert(g.bfs_order(0) == vector<int>({0, 1, 2, 3}));
    cout << "GraphList OK" << endl;
    return 0;
}
