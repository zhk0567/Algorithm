// LeetCode 847: Shortest Path Visiting All Nodes
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        if (n == 1) return 0;
        int target = (1 << n) - 1;
        queue<tuple<int, int, int>> q;
        set<pair<int, int>> seen;
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            q.push({i, mask, 0});
            seen.insert({i, mask});
        }
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == target) return dist;
            for (int v : graph[u]) {
                int nmask = mask | (1 << v);
                pair<int, int> st = {v, nmask};
                if (!seen.count(st)) {
                    seen.insert(st);
                    q.push({v, nmask, dist + 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> g{{1, 2, 3}, {0}, {0}, {0}};
    assert(Solution().shortestPathLength(g) == 4);
    vector<vector<int>> g2{{1}, {0}};
    assert(Solution().shortestPathLength(g2) == 1);
    vector<vector<int>> g3(1);
    assert(Solution().shortestPathLength(g3) == 0);
    cout << "0847 OK" << endl;
    return 0;
}
