// LeetCode 1192: Critical Connections in a Network
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
    vector<vector<int>> g;
    vector<int> dfn, low;
    int timer = 0;
    vector<vector<int>> res;

    void dfs(int u, int p) {
        dfn[u] = low[u] = timer++;
        for (int v : g[u]) {
            if (v == p) continue;
            if (dfn[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    if (u < v) res.push_back({u, v});
                    else res.push_back({v, u});
                }
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.assign(n, {});
        for (auto& e : connections) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfn.assign(n, -1);
        low.assign(n, 0);
        timer = 0;
        res.clear();
        for (int i = 0; i < n; ++i)
            if (dfn[i] == -1) dfs(i, -1);
        return res;
    }
};

int main() {
    vector<vector<int>> c1{{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    auto got = Solution().criticalConnections(4, c1);
    assert(got == vector<vector<int>>({{1, 3}}));
    vector<vector<int>> c2{{0, 1}};
    auto got2 = Solution().criticalConnections(2, c2);
    assert(got2 == vector<vector<int>>({{0, 1}}));
    cout << "1192 OK" << endl;
    return 0;
}
