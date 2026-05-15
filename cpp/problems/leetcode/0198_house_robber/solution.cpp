// LeetCode 198
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0;
        for (int x : nums) {
            int next = max(curr, prev + x);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};

int main() {
    vector<int> a{1, 2, 3, 1};
    assert(Solution().rob(a) == 4);
    vector<int> b{2, 7, 9, 3, 1};
    assert(Solution().rob(b) == 12);
    vector<int> c{};
    assert(Solution().rob(c) == 0);
    cout << "0198 OK" << endl;
    return 0;
}
