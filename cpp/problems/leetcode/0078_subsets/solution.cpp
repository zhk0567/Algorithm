// LeetCode 78
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for (int x : nums) {
            int n = (int)res.size();
            for (int i = 0; i < n; ++i) {
                auto v = res[i];
                v.push_back(x);
                res.push_back(v);
            }
        }
        return res;
    }
};

int main() {
    vector<int> a{1, 2, 3};
    auto out = Solution().subsets(a);
    set<vector<int>> got(out.begin(), out.end());
    set<vector<int>> expect{
        {}, {1}, {2}, {3}, {1, 2},
        {1, 3}, {2, 3}, {1, 2, 3},
    };
    assert(got == expect);
    cout << "0078 OK" << endl;
    return 0;
}
