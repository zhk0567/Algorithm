#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(const vector<vector<pair<int, int>>>& adj, int src) {
    int n = (int)adj.size();
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
    cout << "shortest_path OK" << endl;
    return 0;
}
