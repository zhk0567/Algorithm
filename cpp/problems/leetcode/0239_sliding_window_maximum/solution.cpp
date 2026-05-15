// LeetCode 239
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (dq.front() <= i - k) dq.pop_front();
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main() {
    vector<int> a{1, 3, -1, -3, 5, 3, 6, 7};
    assert((Solution().maxSlidingWindow(a, 3) == vector<int>{3, 3, 5, 5, 6, 7}));
    vector<int> b{1};
    assert((Solution().maxSlidingWindow(b, 1) == vector<int>{1}));
    cout << "0239 OK" << endl;
    return 0;
}
