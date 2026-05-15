// LeetCode 406
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
             });
        vector<vector<int>> res;
        for (auto& p : people) res.insert(res.begin() + p[1], p);
        return res;
    }
};

int main() {
    vector<vector<int>> in{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    auto out = Solution().reconstructQueue(in);
    vector<vector<int>> expect{{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    assert(out == expect);
    cout << "0406 OK" << endl;
    return 0;
}
