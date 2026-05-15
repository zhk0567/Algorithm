// LeetCode 785: Is Graph Bipartite?
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        vector<int> color(n, -1);
        for (int start = 0; start < n; ++start) {
            if (color[start] != -1) continue;
            color[start] = 0;
            queue<int> q;
            q.push(start);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> g1{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    assert(!Solution().isBipartite(g1));
    vector<vector<int>> g2{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    assert(Solution().isBipartite(g2));
    vector<vector<int>> g3(1);
    assert(Solution().isBipartite(g3));
    cout << "0785 OK" << endl;
    return 0;
}
