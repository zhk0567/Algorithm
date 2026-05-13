// LeetCode 416
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums)
            for (int s = target; s >= x; --s)
                if (dp[s - x]) dp[s] = true;
        return dp[target];
    }
};

int main() {
    vector<int> a{1, 5, 11, 5};
    assert(Solution().canPartition(a));
    vector<int> b{1, 2, 3, 5};
    assert(!Solution().canPartition(b));
    vector<int> c{2, 2, 2, 2};
    assert(Solution().canPartition(c));
    cout << "0416 OK" << endl;
    return 0;
}
