// LeetCode 39
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        function<void(int, int)> bt = [&](int start, int remain) {
            if (remain == 0) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < (int)candidates.size(); ++i) {
                if (candidates[i] > remain) break;
                path.push_back(candidates[i]);
                bt(i, remain - candidates[i]);
                path.pop_back();
            }
        };
        bt(0, target);
        return res;
    }
};

int main() {
    vector<int> a{2, 3, 6, 7};
    auto out = Solution().combinationSum(a, 7);
    set<vector<int>> got(out.begin(), out.end());
    set<vector<int>> expect{{2, 2, 3}, {7}};
    assert(got == expect);
    vector<int> b{2, 3, 5};
    auto out2 = Solution().combinationSum(b, 8);
    set<vector<int>> got2(out2.begin(), out2.end());
    set<vector<int>> expect2{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    assert(got2 == expect2);
    cout << "0039 OK" << endl;
    return 0;
}
