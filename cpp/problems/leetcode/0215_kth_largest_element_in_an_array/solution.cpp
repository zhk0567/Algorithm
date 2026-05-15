// LeetCode 215
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
            if ((int)pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> a{3, 2, 1, 5, 6, 4};
    assert(Solution().findKthLargest(a, 2) == 5);
    vector<int> b{3, 2, 3, 1, 2, 4, 5, 5, 6};
    assert(Solution().findKthLargest(b, 4) == 4);
    cout << "0215 OK" << endl;
    return 0;
}
