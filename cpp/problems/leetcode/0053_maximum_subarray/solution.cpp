// LeetCode 53
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long best = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = max<long long>(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return (int)best;
    }
};

int main() {
    vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(Solution().maxSubArray(a) == 6);
    cout << "0053 OK" << endl;
    return 0;
}
