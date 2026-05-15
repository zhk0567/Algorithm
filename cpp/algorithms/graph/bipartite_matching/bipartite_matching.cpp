// 二分图匹配：Kuhn 最大匹配 + 匈牙利最小费用完美匹配
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int kuhnMaxMatching(int nL, int nR, const vector<vector<int>>& adj) {
    vector<int> matchR(nR, -1);
    function<bool(int, vector<char>&)> dfs = [&](int u, vector<char>& seen) -> bool {
        for (int v : adj[u]) {
            if (seen[v]) continue;
            seen[v] = 1;
            if (matchR[v] == -1 || dfs(matchR[v], seen)) {
                matchR[v] = u;
                return true;
            }
        }
        return false;
    };
    int cnt = 0;
    for (int u = 0; u < nL; ++u) {
        vector<char> seen(nR, 0);
        if (dfs(u, seen)) ++cnt;
    }
    return cnt;
}

long long hungarianMinCost(const vector<vector<int>>& cost) {
    int n = (int)cost.size();
    const long long INF = (long long)4e18;
    vector<long long> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<long long> minv(n + 1, INF);
        vector<char> used(n + 1, 0);
        do {
            used[j0] = 1;
            int i0 = (int)p[j0];
            long long delta = INF;
            int j1 = 0;
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    long long cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[(int)p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = (int)way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }
    return -v[0];
}

int main() {
    vector<vector<int>> adj{{0, 1}, {0, 2}, {1, 3}};
    assert(kuhnMaxMatching(3, 4, adj) == 3);
    vector<vector<int>> cm{{4, 1, 3}, {2, 0, 5}, {3, 2, 2}};
    assert(hungarianMinCost(cm) == 5);
    cout << "bipartite_matching OK" << endl;
    return 0;
}
