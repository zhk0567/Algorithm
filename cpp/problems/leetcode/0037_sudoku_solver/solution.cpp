// LeetCode 37
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};
        vector<pair<int, int>> empties;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.')
                    empties.emplace_back(i, j);
                else {
                    int d = ch - '1';
                    int mask = 1 << d;
                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[(i / 3) * 3 + j / 3] |= mask;
                }
            }
        function<bool(int)> bt = [&](int k) {
            if (k == (int)empties.size()) return true;
            auto [i, j] = empties[k];
            int b = (i / 3) * 3 + j / 3;
            int used = rows[i] | cols[j] | boxes[b];
            for (int d = 0; d < 9; ++d) {
                int mask = 1 << d;
                if (used & mask) continue;
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[b] |= mask;
                board[i][j] = char('1' + d);
                if (bt(k + 1)) return true;
                rows[i] ^= mask;
                cols[j] ^= mask;
                boxes[b] ^= mask;
                board[i][j] = '.';
            }
            return false;
        };
        bt(0);
    }
};

int main() {
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    Solution().solveSudoku(board);
    for (auto& row : board) {
        set<char> s(row.begin(), row.end());
        assert(s.size() == 9 && *s.begin() == '1' && *s.rbegin() == '9');
    }
    cout << "0037 OK" << endl;
    return 0;
}
