#include <bits/stdc++.h>
using namespace std;

struct GraphMatrix {
    int n;
    bool directed;
    vector<vector<int>> mat;
    GraphMatrix(int n_, bool d = false) : n(n_), directed(d), mat(n_, vector<int>(n_, 0)) {}

    void add_edge(int u, int v, int w = 1) {
        mat[u][v] = w;
        if (!directed) mat[v][u] = w;
    }

    bool has_edge(int u, int v) const { return mat[u][v] != 0; }

    vector<int> neighbors(int u) const {
        vector<int> out;
        for (int v = 0; v < n; ++v)
            if (mat[u][v]) out.push_back(v);
        return out;
    }
};

int main() {
    GraphMatrix g(3, false);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    assert(g.has_edge(0, 1) && g.has_edge(1, 0));
    assert(g.neighbors(0) == vector<int>({1}));
    cout << "GraphMatrix OK" << endl;
    return 0;
}
