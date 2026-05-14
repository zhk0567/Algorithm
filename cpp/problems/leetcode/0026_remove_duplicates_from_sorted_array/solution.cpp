// LeetCode 26
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;
        for (int i = 1; i < static_cast<int>(nums.size()); ++i)
            if (nums[i] != nums[k - 1]) nums[k++] = nums[i];
        return k;
    }
};

int main() {
    vector<int> a{1, 1, 2};
    int k = Solution().removeDuplicates(a);
    assert(k == 2 && a[0] == 1 && a[1] == 2);
    vector<int> b{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = Solution().removeDuplicates(b);
    assert(k2 == 5);
    cout << "0026 OK" << endl;
    return 0;
}
