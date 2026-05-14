// LeetCode 8
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = (int)s.size();
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            ++i;
        }
        long long x = 0;
        while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {
            x = x * 10 + (s[i] - '0');
            if (sign * x > INT_MAX) return INT_MAX;
            if (sign * x < INT_MIN) return INT_MIN;
            ++i;
        }
        return static_cast<int>(sign * x);
    }
};

int main() {
    assert(Solution().myAtoi("42") == 42);
    assert(Solution().myAtoi("   -42") == -42);
    assert(Solution().myAtoi("4193 with words") == 4193);
    assert(Solution().myAtoi("words and 987") == 0);
    assert(Solution().myAtoi("-91283472332") == INT_MIN);
    assert(Solution().myAtoi("+1") == 1);
    cout << "0008 OK" << endl;
    return 0;
}
