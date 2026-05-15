// LeetCode 684: Redundant Connection
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf((int)edges.size() + 1);
        for (auto& e : edges) {
            if (!uf.unite(e[0], e[1])) return e;
        }
        return {};
    }
};

int main() {
    vector<vector<int>> e1{{1, 2}, {1, 3}, {2, 3}};
    auto got1 = Solution().findRedundantConnection(e1);
    assert(got1 == vector<int>({2, 3}));
    vector<vector<int>> e2{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  auto got = Solution().findRedundantConnection(e2);
    assert(got == vector<int>({1, 4}));
    cout << "0684 OK" << endl;
    return 0;
}
