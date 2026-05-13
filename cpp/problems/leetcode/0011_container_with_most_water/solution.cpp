// LeetCode 11
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = static_cast<int>(height.size()) - 1, best = 0;
        while (l < r) {
            int h = min(height[l], height[r]);
            best = max(best, h * (r - l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return best;
    }
};

int main() {
    vector<int> h{1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(Solution().maxArea(h) == 49);
    cout << "0011 OK" << endl;
    return 0;
}
