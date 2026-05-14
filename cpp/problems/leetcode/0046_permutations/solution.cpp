// LeetCode 46
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        function<void()> bt = [&]() {
            if (path.size() == nums.size()) {
                res.push_back(path);
                return;
            }
            for (size_t i = 0; i < nums.size(); ++i) {
                if (used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                bt();
                path.pop_back();
                used[i] = false;
            }
        };
        bt();
        return res;
    }
};

int main() {
    vector<int> a{1, 2, 3};
    auto out = Solution().permute(a);
    set<vector<int>> got(out.begin(), out.end());
    set<vector<int>> expect{
        {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
        {2, 3, 1}, {3, 1, 2}, {3, 2, 1},
    };
    assert(got == expect);
    cout << "0046 OK" << endl;
    return 0;
}
