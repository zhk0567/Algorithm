// LeetCode 70
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        long long a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            long long c = a + b;
            a = b;
            b = c;
        }
        return (int)b;
    }
};

int main() {
    assert(Solution().climbStairs(3) == 3);
    assert(Solution().climbStairs(5) == 8);
    cout << "0070 OK" << endl;
    return 0;
}
