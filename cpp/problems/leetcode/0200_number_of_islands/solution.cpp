// LeetCode 200
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = (int)grid.size(), n = (int)grid[0].size(), cnt = 0;
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
            grid[i][j] = '0';
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(i, j);
                }
        return cnt;
    }
};

int main() {
    vector<vector<char>> g1{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    assert(Solution().numIslands(g1) == 1);
    vector<vector<char>> g2{
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    assert(Solution().numIslands(g2) == 3);
    cout << "0200 OK" << endl;
    return 0;
}
