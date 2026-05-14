#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int edmonds_karp(vector<vector<int>> g, int s, int t) {
    int n = (int)g.size();
    int flow = 0;
    while (true) {
        vector<int> parent(n, -1);
        queue<int> q;
        parent[s] = s;
        q.push(s);
        while (!q.empty() && parent[t] == -1) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v)
                if (parent[v] == -1 && g[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
        }
        if (parent[t] == -1) break;
        int add = INT_MAX;
        for (int v = t; v != s; v = parent[v]) add = min(add, g[parent[v]][v]);
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            g[u][v] -= add;
            g[v][u] += add;
        }
        flow += add;
    }
    return flow;
}

int main() {
    vector<vector<int>> cap(4, vector<int>(4, 0));
    cap[0][1] = 3;
    cap[0][2] = 2;
    cap[1][2] = 1;
    cap[1][3] = 2;
    cap[2][3] = 3;
    assert(edmonds_karp(cap, 0, 3) == 5);
    cout << "network_flow OK" << endl;
    return 0;
}
