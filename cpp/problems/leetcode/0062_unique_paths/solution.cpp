// LeetCode 62
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) row[j] += row[j - 1];
        return row.back();
    }
};

int main() {
    assert(Solution().uniquePaths(3, 7) == 28);
    assert(Solution().uniquePaths(3, 2) == 3);
    assert(Solution().uniquePaths(1, 1) == 1);
    cout << "0062 OK" << endl;
    return 0;
}
