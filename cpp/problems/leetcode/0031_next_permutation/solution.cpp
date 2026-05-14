// LeetCode 31
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size(), i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    vector<int> a{1, 2, 3};
    Solution().nextPermutation(a);
    assert((a == vector<int>{1, 3, 2}));
    vector<int> b{3, 2, 1};
    Solution().nextPermutation(b);
    assert((b == vector<int>{1, 2, 3}));
    vector<int> c{1, 1, 5};
    Solution().nextPermutation(c);
    assert((c == vector<int>{1, 5, 1}));
    cout << "0031 OK" << endl;
    return 0;
}
