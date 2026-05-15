// LeetCode 992: Subarrays with K Different Integers
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
    int atMost(const vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> cnt;
        int left = 0, res = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            ++cnt[nums[right]];
            while ((int)cnt.size() > k) {
                int y = nums[left++];
                if (--cnt[y] == 0) cnt.erase(y);
            }
            res += right - left + 1;
        }
        return res;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    vector<int> a{1, 2, 1, 2, 3};
    assert(Solution().subarraysWithKDistinct(a, 2) == 7);
    vector<int> b{1, 2, 1, 3, 4};
    assert(Solution().subarraysWithKDistinct(b, 3) == 3);
    vector<int> c{1, 1, 1};
    assert(Solution().subarraysWithKDistinct(c, 1) == 6);
    cout << "0992 OK" << endl;
    return 0;
}
