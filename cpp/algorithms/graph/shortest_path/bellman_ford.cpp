// Bellman–Ford 单源最短路（可有负权边；可判负环）
#include <alg_std.hpp>
#include <cassert>
using namespace std;

optional<vector<long long>> bellman_ford(
    int n, const vector<array<int, 3>>& edges, int src) {
    const long long INF = (long long)4e18;
    vector<long long> dist(n, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) return nullopt;
    }
    return dist;
}

int main() {
    vector<array<int, 3>> e{{0, 1, 4}, {0, 2, 5}, {1, 2, -2}};
    auto d = bellman_ford(3, e, 0);
    assert(d && *d == vector<long long>({0, 4, 2}));

    vector<array<int, 3>> neg{{0, 1, 1}, {1, 2, -1}, {2, 0, -1}};
    assert(!bellman_ford(3, neg, 0));
    cout << "bellman_ford OK" << endl;
    return 0;
}
