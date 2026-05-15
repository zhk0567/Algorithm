// LeetCode 18
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long s = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (s < target)
                        ++l;
                    else if (s > target)
                        --r;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int xl = nums[l], yr = nums[r];
                        while (l < r && nums[l] == xl) ++l;
                        while (l < r && nums[r] == yr) --r;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> a{1, 0, -1, 0, -2, 2};
    auto out = Solution().fourSum(a, 0);
    set<vector<int>> got(out.begin(), out.end());
    set<vector<int>> expect{
        {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1},
    };
    assert(got == expect);
    vector<int> b{2, 2, 2, 2, 2};
    assert((Solution().fourSum(b, 8) == vector<vector<int>>{{2, 2, 2, 2}}));
    cout << "0018 OK" << endl;
    return 0;
}
