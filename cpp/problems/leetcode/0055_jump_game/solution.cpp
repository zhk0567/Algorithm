// LeetCode 55
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size(), far = 0;
        for (int i = 0; i < n; ++i) {
            if (i > far) return false;
            far = max(far, i + nums[i]);
            if (far >= n - 1) return true;
        }
        return true;
    }
};

int main() {
    vector<int> a{2, 3, 1, 1, 4};
    assert(Solution().canJump(a));
    vector<int> b{3, 2, 1, 0, 4};
    assert(!Solution().canJump(b));
    vector<int> c{0};
    assert(Solution().canJump(c));
    cout << "0055 OK" << endl;
    return 0;
}
