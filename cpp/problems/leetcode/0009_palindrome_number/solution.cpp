// LeetCode 9
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        long long rev = 0;
        int xx = x;
        while (xx > rev) {
            rev = rev * 10 + xx % 10;
            xx /= 10;
        }
        return xx == rev || xx == rev / 10;
    }
};

int main() {
    assert(Solution().isPalindrome(121));
    assert(!Solution().isPalindrome(-121));
    assert(Solution().isPalindrome(0));
    assert(!Solution().isPalindrome(10));
    cout << "0009 OK" << endl;
    return 0;
}
