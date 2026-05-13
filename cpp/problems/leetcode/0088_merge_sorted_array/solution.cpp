// LeetCode 88
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> a{1, 2, 3, 0, 0, 0};
    vector<int> b{2, 5, 6};
    Solution().merge(a, 3, b, 3);
    assert((a == vector<int>{1, 2, 2, 3, 5, 6}));
    vector<int> c{1};
    vector<int> d{};
    Solution().merge(c, 1, d, 0);
    assert((c == vector<int>{1}));
    vector<int> e{0};
    vector<int> f{1};
    Solution().merge(e, 0, f, 1);
    assert((e == vector<int>{1}));
    cout << "0088 OK" << endl;
    return 0;
}
