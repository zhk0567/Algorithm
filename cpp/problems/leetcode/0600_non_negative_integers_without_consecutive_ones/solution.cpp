// LeetCode 600: Non-negative Integers Without Consecutive Ones
#include <alg_std.hpp>
#include <bitset>
#include <cassert>
using namespace std;

class Solution {
    string s;
    vector<vector<vector<int>>> memo;

    int dfs(int i, bool tight, bool prev1) {
        if (i == (int)s.size()) return 1;
        int& cell = memo[i][tight][prev1];
        if (cell != -1) return cell;
        int limit = tight ? (s[i] - '0') : 1;
        int total = 0;
        for (int d = 0; d <= limit; ++d) {
            if (d == 1 && prev1) continue;
            total += dfs(i + 1, tight && d == limit, d == 1);
        }
        return cell = total;
    }

public:
    int findIntegers(int n) {
        if (n == 0) return 1;
        s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));
        memo.assign(s.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return dfs(0, true, false);
    }
};

int main() {
    assert(Solution().findIntegers(5) == 5);
    assert(Solution().findIntegers(1) == 2);
    assert(Solution().findIntegers(0) == 1);
    assert(Solution().findIntegers(10) == 8);
    cout << "0600 OK" << endl;
    return 0;
}
