#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rankv;
    // 按大小合并：可维护 vector<int> sz，unite 时 if (sz[ra] < sz[rb]) swap(ra,rb); parent[rb]=ra; sz[ra]+=sz[rb];

    explicit UnionFind(int n) : parent(n), rankv(n, 0) { iota(parent.begin(), parent.end(), 0); }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (rankv[ra] < rankv[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rankv[ra] == rankv[rb]) ++rankv[ra];
        return true;
    }
};

int main() {
    UnionFind uf(5);
    assert(uf.unite(0, 1) && uf.unite(1, 2));
    assert(uf.find(0) == uf.find(2));
    assert(!uf.unite(0, 2));
    cout << "UnionFind OK" << endl;
    return 0;
}
