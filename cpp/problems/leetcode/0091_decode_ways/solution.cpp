// LeetCode 91
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int prev2 = 1, prev1 = 1;
        for (int i = 1; i < (int)s.size(); ++i) {
            int cur = 0;
            if (s[i] != '0') cur += prev1;
            int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (two >= 10 && two <= 26) cur += prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main() {
    assert(Solution().numDecodings("12") == 2);
    assert(Solution().numDecodings("226") == 3);
    assert(Solution().numDecodings("06") == 0);
    assert(Solution().numDecodings("0") == 0);
    assert(Solution().numDecodings("10") == 1);
    cout << "0091 OK" << endl;
    return 0;
}
