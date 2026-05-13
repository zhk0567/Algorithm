// LeetCode 152
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int mx = nums[0], mn = nums[0], best = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            int x = nums[i];
            int a = mx * x, b = mn * x;
            mx = max({x, a, b});
            mn = min({x, a, b});
            best = max(best, mx);
        }
        return best;
    }
};

int main() {
    vector<int> a{2, 3, -2, 4};
    assert(Solution().maxProduct(a) == 6);
    vector<int> b{-2, 0, -1};
    assert(Solution().maxProduct(b) == 0);
    vector<int> c{-2, 3, -4};
    assert(Solution().maxProduct(c) == 24);
    cout << "0152 OK" << endl;
    return 0;
}
