// LeetCode 51
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cur;
        vector<bool> cols(n, false), d1(2 * n, false), d2(2 * n, false);
        function<void(int)> bt = [&](int r) {
            if (r == n) {
                vector<string> board(n, string(n, '.'));
                for (int i = 0; i < n; ++i) board[i][cur[i]] = 'Q';
                res.push_back(board);
                return;
            }
            for (int c = 0; c < n; ++c) {
                if (cols[c] || d1[r - c + n] || d2[r + c]) continue;
                cols[c] = d1[r - c + n] = d2[r + c] = true;
                cur.push_back(c);
                bt(r + 1);
                cur.pop_back();
                cols[c] = d1[r - c + n] = d2[r + c] = false;
            }
        };
        bt(0);
        return res;
    }
};

int main() {
    assert((int)Solution().solveNQueens(4).size() == 2);
    assert((Solution().solveNQueens(1) == vector<vector<string>>{{"Q"}}));
    assert((int)Solution().solveNQueens(8).size() == 92);
    cout << "0051 OK" << endl;
    return 0;
}
