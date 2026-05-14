// LeetCode 238
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> out(n, 1);
        for (int i = 1; i < n; ++i) out[i] = out[i - 1] * nums[i - 1];
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            out[i] *= right;
            right *= nums[i];
        }
        return out;
    }
};

int main() {
    vector<int> a{1, 2, 3, 4};
    assert((Solution().productExceptSelf(a) == vector<int>{24, 12, 8, 6}));
    vector<int> b{-1, 1, 0, -3, 3};
    assert((Solution().productExceptSelf(b) == vector<int>{0, 0, 9, 0, 0}));
    cout << "0238 OK" << endl;
    return 0;
}
