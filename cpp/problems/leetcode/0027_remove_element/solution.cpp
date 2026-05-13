// LeetCode 27
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int w = 0;
        for (int x : nums)
            if (x != val) nums[w++] = x;
        return w;
    }
};

int main() {
    vector<int> a{3, 2, 2, 3};
    int k = Solution().removeElement(a, 3);
    sort(a.begin(), a.begin() + k);
    assert(k == 2 && a[0] == 2 && a[1] == 2);
    vector<int> b{0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = Solution().removeElement(b, 2);
    sort(b.begin(), b.begin() + k2);
    assert((vector<int>(b.begin(), b.begin() + k2) == vector<int>{0, 0, 1, 3, 4}));
    cout << "0027 OK" << endl;
    return 0;
}
