// LeetCode 45
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, end = 0, far = 0;
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            far = max(far, i + nums[i]);
            if (i == end) {
                ++steps;
                end = far;
            }
        }
        return steps;
    }
};

int main() {
    vector<int> a{2, 3, 1, 1, 4};
    assert(Solution().jump(a) == 2);
    vector<int> b{2, 3, 0, 1, 4};
    assert(Solution().jump(b) == 2);
    vector<int> c{0};
    assert(Solution().jump(c) == 0);
    cout << "0045 OK" << endl;
    return 0;
}
