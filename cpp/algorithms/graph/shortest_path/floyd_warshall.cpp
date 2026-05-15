// Floyd–Warshall 全源最短路（可有负权；可判负环）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

optional<vector<vector<long long>>> floyd_warshall(
    int n, const vector<array<int, 3>>& edges) {
    const long long INF = (long long)4e15;
    vector dist(n, vector<long long>(n, INF));
    for (int i = 0; i < n; ++i) dist[i][i] = 0;
    for (auto [u, v, w] : edges) dist[u][v] = min(dist[u][v], (long long)w);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                long long w = dist[i][k] + dist[k][j];
                if (w < dist[i][j]) dist[i][j] = w;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) return nullopt;
    }
    return dist;
}

int main() {
    vector<array<int, 3>> e{{0, 1, 2}, {1, 2, 1}, {0, 2, 5}};
    auto d = floyd_warshall(3, e);
    assert(d);
    assert((*d)[0] == vector<long long>({0, 2, 3}));
    assert((*d)[1][2] == 1);

    vector<array<int, 3>> neg{{0, 1, 1}, {1, 2, -2}, {2, 0, -1}};
    assert(!floyd_warshall(3, neg));
    cout << "floyd_warshall OK" << endl;
    return 0;
}
