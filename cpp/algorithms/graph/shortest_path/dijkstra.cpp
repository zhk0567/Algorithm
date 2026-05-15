#include <bits/stdc++.h>
#include <cassert>
using namespace std;

vector<long long> dijkstra(const vector<vector<pair<int, int>>>& adj, int src) {
    int n = (int)adj.size();
    for (int u = 0; u < n; ++u)
        for (auto [v, w] : adj[u])
            if (w < 0) throw runtime_error("negative edge weight; use Bellman-Ford");
    const long long INF = (long long)4e18;
    vector<long long> dist(n, INF);
    dist[src] = 0;
    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<pair<int, int>>> g(3);
    g[0].push_back({1, 2});
    g[1].push_back({0, 2});
    g[0].push_back({2, 5});
    g[2].push_back({0, 5});
    g[1].push_back({2, 1});
    g[2].push_back({1, 1});
    auto d = dijkstra(g, 0);
    assert(d == vector<long long>({0, 2, 3}));
    assert(dijkstra(vector<vector<pair<int, int>>>{vector<pair<int, int>>{}}, 0) == vector<long long>{0});
    vector<vector<pair<int, int>>> g2(2);
    g2[1].push_back({0, 1});
    assert(dijkstra(g2, 0)[1] == (long long)4e18);
    try {
        vector<vector<pair<int, int>>> neg(2);
        neg[0].push_back({1, -1});
        neg[1].push_back({0, -1});
        dijkstra(neg, 0);
        assert(false);
    } catch (const runtime_error&) {
    }
    cout << "shortest_path OK" << endl;
    return 0;
}
