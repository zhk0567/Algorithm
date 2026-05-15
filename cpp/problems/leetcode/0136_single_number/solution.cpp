// LeetCode 136
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums) x ^= n;
        return x;
    }
};

int main() {
    vector<int> a{2, 2, 1};
    assert(Solution().singleNumber(a) == 1);
    vector<int> b{4, 1, 2, 1, 2};
    assert(Solution().singleNumber(b) == 4);
    cout << "0136 OK" << endl;
    return 0;
}
