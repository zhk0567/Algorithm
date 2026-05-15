// LeetCode 283
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w = 0;
        for (int x : nums)
            if (x != 0) nums[w++] = x;
        for (int i = w; i < (int)nums.size(); ++i) nums[i] = 0;
    }
};

int main() {
    vector<int> a{0, 1, 0, 3, 12};
    Solution().moveZeroes(a);
    assert((a == vector<int>{1, 3, 12, 0, 0}));
    vector<int> b{0};
    Solution().moveZeroes(b);
    assert((b == vector<int>{0}));
    cout << "0283 OK" << endl;
    return 0;
}
