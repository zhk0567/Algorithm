// LeetCode 994: Rotting Oranges
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        queue<array<int, 3>> q;
        int fresh = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2)
                    q.push({i, j, 0});
                else if (grid[i][j] == 1)
                    ++fresh;
        if (!fresh) return 0;
        int minutes = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [i, j, t] = q.front();
            q.pop();
            minutes = max(minutes, t);
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    --fresh;
                    q.push({ni, nj, t + 1});
                }
            }
        }
        return fresh ? -1 : minutes;
    }
};

int main() {
    vector<vector<int>> g{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    assert(Solution().orangesRotting(g) == 4);
    vector<vector<int>> g2{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    assert(Solution().orangesRotting(g2) == -1);
    vector<vector<int>> g3{{0}};
    assert(Solution().orangesRotting(g3) == 0);
    cout << "0994 OK" << endl;
    return 0;
}
