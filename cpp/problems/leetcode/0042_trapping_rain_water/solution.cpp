// LeetCode 42
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = static_cast<int>(height.size());
        if (n == 0) return 0;
        int l = 0, r = n - 1, lm = 0, rm = 0, ans = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= lm)
                    lm = height[l];
                else
                    ans += lm - height[l];
                ++l;
            } else {
                if (height[r] >= rm)
                    rm = height[r];
                else
                    ans += rm - height[r];
                --r;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> a{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(Solution().trap(a) == 6);
    vector<int> b{4, 2, 0, 3, 2, 5};
    assert(Solution().trap(b) == 9);
    cout << "0042 OK" << endl;
    return 0;
}
