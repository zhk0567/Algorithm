// LeetCode 560
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int s = 0, ans = 0;
        for (int x : nums) {
            s += x;
            auto it = cnt.find(s - k);
            if (it != cnt.end()) ans += it->second;
            ++cnt[s];
        }
        return ans;
    }
};

int main() {
    vector<int> a{1, 1, 1};
    assert(Solution().subarraySum(a, 2) == 2);
    vector<int> b{1, 2, 3};
    assert(Solution().subarraySum(b, 3) == 2);
    vector<int> c{1, -1, 1, -1};
    assert(Solution().subarraySum(c, 0) == 4);
    cout << "0560 OK" << endl;
    return 0;
}
