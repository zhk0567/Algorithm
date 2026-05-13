// LeetCode 79
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = (int)board.size(), n = (int)board[0].size();
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
            if (k == (int)word.size()) return true;
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
                return false;
            char tmp = board[i][j];
            board[i][j] = '#';
            bool ok = dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1) ||
                      dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1);
            board[i][j] = tmp;
            return ok;
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(i, j, 0)) return true;
        return false;
    }
};

int main() {
    vector<vector<char>> b{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    assert(Solution().exist(b, "ABCCED"));
    assert(Solution().exist(b, "SEE"));
    assert(!Solution().exist(b, "ABCB"));
    cout << "0079 OK" << endl;
    return 0;
}
