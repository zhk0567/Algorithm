// LeetCode 300
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end())
                tails.push_back(x);
            else
                *it = x;
        }
        return static_cast<int>(tails.size());
    }
};

int main() {
    vector<int> a{10, 9, 2, 5, 3, 7, 101, 18};
    assert(Solution().lengthOfLIS(a) == 4);
    vector<int> b{0, 1, 0, 3, 2, 3};
    assert(Solution().lengthOfLIS(b) == 4);
    vector<int> c{7, 7, 7, 7, 7, 7, 7};
    assert(Solution().lengthOfLIS(c) == 1);
    cout << "0300 OK" << endl;
    return 0;
}
