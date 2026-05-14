// LeetCode 287
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    vector<int> a{1, 3, 4, 2, 2};
    assert(Solution().findDuplicate(a) == 2);
    vector<int> b{3, 1, 3, 4, 2};
    assert(Solution().findDuplicate(b) == 3);
    vector<int> c{1, 1};
    assert(Solution().findDuplicate(c) == 1);
    cout << "0287 OK" << endl;
    return 0;
}
