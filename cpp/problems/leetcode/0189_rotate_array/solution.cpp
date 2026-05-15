// LeetCode 189
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n == 0) return;
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    Solution().rotate(a, 3);
    assert((a == vector<int>{5, 6, 7, 1, 2, 3, 4}));
    vector<int> b{-1, -100, 3, 99};
    Solution().rotate(b, 2);
    assert((b == vector<int>{3, 99, -1, -100}));
    cout << "0189 OK" << endl;
    return 0;
}
