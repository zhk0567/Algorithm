// LeetCode 1: Two Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int need = target - nums[i];
            auto it = seen.find(need);
            if (it != seen.end())
                return {it->second, i};
            seen[nums[i]] = i;
        }
        return {};
    }
};

vector<int> two_sum_brute(vector<int>& nums, int target) {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (nums[i] + nums[j] == target)
                return {i, j};
    return {};
}

int main() {
    vector<int> nums{2, 7, 11, 15};
    auto ans = Solution().twoSum(nums, 9);
    assert(ans.size() == 2 && ans[0] == 0 && ans[1] == 1);
    cout << ans[0] << "," << ans[1] << endl; // 0,1

    auto brute = two_sum_brute(nums, 9);
    assert(brute == ans);
    return 0;
}
