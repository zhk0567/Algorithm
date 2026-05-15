// LeetCode 56
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        vector<vector<int>> res{intervals[0]};
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> a{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    assert((Solution().merge(a) == vector<vector<int>>{{1, 6}, {8, 10}, {15, 18}}));
    vector<vector<int>> b{{1, 4}, {4, 5}};
    assert((Solution().merge(b) == vector<vector<int>>{{1, 5}}));
    vector<vector<int>> e{};
    assert(Solution().merge(e).empty());
    cout << "0056 OK" << endl;
    return 0;
}
