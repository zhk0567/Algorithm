// LeetCode 33
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = static_cast<int>(nums.size()) - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) return m;
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> a{4, 5, 6, 7, 0, 1, 2};
    assert(Solution().search(a, 0) == 4);
    assert(Solution().search(a, 3) == -1);
    vector<int> b{1};
    assert(Solution().search(b, 0) == -1);
    assert(Solution().search(b, 1) == 0);
    cout << "0033 OK" << endl;
    return 0;
}
