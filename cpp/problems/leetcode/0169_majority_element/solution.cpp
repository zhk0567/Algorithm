// LeetCode 169
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0, cnt = 0;
        for (int x : nums) {
            if (cnt == 0) cand = x;
            cnt += (x == cand) ? 1 : -1;
        }
        return cand;
    }
};

int main() {
    vector<int> a{3, 2, 3};
    assert(Solution().majorityElement(a) == 3);
    vector<int> b{2, 2, 1, 1, 1, 2, 2};
    assert(Solution().majorityElement(b) == 2);
    cout << "0169 OK" << endl;
    return 0;
}
