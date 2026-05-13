// LeetCode 35
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }
};

int main() {
    vector<int> a{1, 3, 5, 6};
    assert(Solution().searchInsert(a, 5) == 2);
    assert(Solution().searchInsert(a, 2) == 1);
    assert(Solution().searchInsert(a, 7) == 4);
    assert(Solution().searchInsert(a, 0) == 0);
    cout << "0035 OK" << endl;
    return 0;
}
