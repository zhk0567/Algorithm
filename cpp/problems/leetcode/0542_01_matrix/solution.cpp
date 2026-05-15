// LeetCode 542: 01 Matrix
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = (int)mat.size(), n = (int)mat[0].size();
        const int inf = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, inf));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        return dist;
    }
};

int main() {
    vector<vector<int>> g1{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    auto r1 = Solution().updateMatrix(g1);
    vector<vector<int>> want1{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    assert(r1 == want1);
    vector<vector<int>> g2{{0, 0, 0}, {0, 0, 0}, {0, 1, 0}};
    auto r2 = Solution().updateMatrix(g2);
    vector<vector<int>> want2{{0, 0, 0}, {0, 0, 0}, {0, 1, 0}};
    assert(r2 == want2);
    cout << "0542 OK" << endl;
    return 0;
}
