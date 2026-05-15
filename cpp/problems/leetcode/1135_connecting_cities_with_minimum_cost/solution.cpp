// LeetCode 1135: Connecting Cities With Minimum Cost
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

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<array<int, 3>> edges;
        for (auto& e : connections) edges.push_back({e[2], e[0], e[1]});
        sort(edges.begin(), edges.end());
        UF uf(n + 1);
        int total = 0, cnt = 0;
        for (auto [c, u, v] : edges) {
            if (uf.unite(u, v)) {
                total += c;
                if (++cnt == n - 1) return total;
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> c1{{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    assert(Solution().minimumCost(3, c1) == 6);
    vector<vector<int>> c2{{1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {1, 4, 3}};
    assert(Solution().minimumCost(4, c2) == 4);
    vector<vector<int>> c3{{1, 2, 5}};
    assert(Solution().minimumCost(2, c3) == 5);
    cout << "1135 OK" << endl;
    return 0;
}
