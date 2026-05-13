// LeetCode 41
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i)
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};

int main() {
    vector<int> a{1, 2, 0};
    assert(Solution().firstMissingPositive(a) == 3);
    vector<int> b{3, 4, -1, 1};
    assert(Solution().firstMissingPositive(b) == 2);
    vector<int> c{7, 8, 9, 11, 12};
    assert(Solution().firstMissingPositive(c) == 1);
    vector<int> d{};
    assert(Solution().firstMissingPositive(d) == 1);
    cout << "0041 OK" << endl;
    return 0;
}
