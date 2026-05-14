// LeetCode 34
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        auto hi = upper_bound(nums.begin(), nums.end(), target);
        if (lo == hi) return {-1, -1};
        return {(int)(lo - nums.begin()), (int)(hi - nums.begin() - 1)};
    }
};

int main() {
    vector<int> a{5, 7, 7, 8, 8, 10};
    assert((Solution().searchRange(a, 8) == vector<int>{3, 4}));
    assert((Solution().searchRange(a, 6) == vector<int>{-1, -1}));
    vector<int> e{};
    assert((Solution().searchRange(e, 0) == vector<int>{-1, -1}));
    cout << "0034 OK" << endl;
    return 0;
}
