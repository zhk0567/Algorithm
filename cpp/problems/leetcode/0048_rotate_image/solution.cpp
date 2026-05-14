// LeetCode 48
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (auto& row : matrix) reverse(row.begin(), row.end());
    }
};

int main() {
    vector<vector<int>> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution().rotate(a);
    assert((a == vector<vector<int>>{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}));
    cout << "0048 OK" << endl;
    return 0;
}
