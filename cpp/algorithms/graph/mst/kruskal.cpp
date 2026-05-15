#include <alg_std.hpp>
#include <cassert>
using namespace std;

struct UF {
    vector<int> p, r;
    explicit UF(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (r[ra] < r[rb]) swap(ra, rb);
        p[rb] = ra;
        if (r[ra] == r[rb]) ++r[ra];
        return true;
    }
};

int kruskal(int n, vector<array<int, 3>> edges) {
    if (n <= 1) return 0;
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
    UF uf(n);
    int tot = 0, cnt = 0;
    for (auto [u, v, w] : edges) {
        if (uf.unite(u, v)) {
            tot += w;
            if (++cnt == n - 1) break;
        }
    }
    if (cnt < n - 1) throw runtime_error("graph is not connected");
    return tot;
}

int main() {
    vector<array<int, 3>> e{{0, 1, 4}, {1, 2, 3}, {0, 2, 2}};
    assert(kruskal(3, e) == 5);
    assert(kruskal(1, {}) == 0);
    try {
        kruskal(2, {});
        assert(false);
    } catch (const runtime_error&) {
    }
    cout << "mst OK" << endl;
    return 0;
}
