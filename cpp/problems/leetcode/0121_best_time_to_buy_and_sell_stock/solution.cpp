// LeetCode 121
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lo = INT_MAX, best = 0;
        for (int p : prices) {
            lo = min(lo, p);
            best = max(best, p - lo);
        }
        return best;
    }
};

int main() {
    vector<int> a{7, 1, 5, 3, 6, 4};
    assert(Solution().maxProfit(a) == 5);
    vector<int> b{7, 6, 4, 3, 1};
    assert(Solution().maxProfit(b) == 0);
    cout << "0121 OK" << endl;
    return 0;
}
