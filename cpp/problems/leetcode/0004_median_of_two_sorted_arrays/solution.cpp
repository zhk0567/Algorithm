// LeetCode 4
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *A = &nums1, *B = &nums2;
        if (A->size() > B->size()) swap(A, B);
        int m = (int)A->size(), n = (int)B->size();
        int lo = 0, hi = m, half = (m + n + 1) / 2;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = half - i;
            long long aL = i ? (*A)[i - 1] : LLONG_MIN / 4;
            long long aR = i < m ? (*A)[i] : LLONG_MAX / 4;
            long long bL = j ? (*B)[j - 1] : LLONG_MIN / 4;
            long long bR = j < n ? (*B)[j] : LLONG_MAX / 4;
            if (aL <= bR && bL <= aR) {
                if ((m + n) % 2) return (double)max(aL, bL);
                return (max(aL, bL) + min(aR, bR)) / 2.0;
            }
            if (aL > bR)
                hi = i - 1;
            else
                lo = i + 1;
        }
        return 0;
    }
};

int main() {
    vector<int> a{1, 3}, b{2};
    assert(Solution().findMedianSortedArrays(a, b) == 2.0);
    vector<int> c{1, 2}, d{3, 4};
    assert(Solution().findMedianSortedArrays(c, d) == 2.5);
    cout << "0004 OK" << endl;
    return 0;
}
