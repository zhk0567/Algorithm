// LeetCode 15
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;
            int l = i + 1, r = n - 1;
            while (l < r) {
                long long s = (long long)nums[i] + nums[l] + nums[r];
                if (s < 0)
                    ++l;
                else if (s > 0)
                    --r;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int xl = nums[l], yr = nums[r];
                    while (l < r && nums[l] == xl) ++l;
                    while (l < r && nums[r] == yr) --r;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> a{-1, 0, 1, 2, -1, -4};
    auto out = Solution().threeSum(a);
    set<array<int, 3>> st;
    for (auto& v : out) st.insert({v[0], v[1], v[2]});
    assert(st.count({-1, -1, 2}) && st.count({-1, 0, 1}) && st.size() == 2u);
    cout << "0015 OK" << endl;
    return 0;
}
