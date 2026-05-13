// LeetCode 7
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long xx = x, rev = 0;
        while (xx != 0) {
            rev = rev * 10 + xx % 10;
            xx /= 10;
            if (rev > INT_MAX || rev < INT_MIN)
                return 0;
        }
        return static_cast<int>(rev);
    }
};

int main() {
    assert(Solution().reverse(123) == 321);
    assert(Solution().reverse(-123) == -321);
    assert(Solution().reverse(120) == 21);
    assert(Solution().reverse(1534236469) == 0);
    cout << "0007 OK" << endl;
    return 0;
}
