// LeetCode 75
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1, i = 0;
        while (i <= r) {
            if (nums[i] == 0)
                swap(nums[l++], nums[i++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[r--]);
            else
                ++i;
        }
    }
};

int main() {
    vector<int> a{2, 0, 2, 1, 1, 0};
    Solution().sortColors(a);
    assert((a == vector<int>{0, 0, 1, 1, 2, 2}));
    vector<int> b{2, 0, 1};
    Solution().sortColors(b);
    assert((b == vector<int>{0, 1, 2}));
    cout << "0075 OK" << endl;
    return 0;
}
