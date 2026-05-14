// LeetCode 5
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size(), st = 0, en = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l > en - st) st = l, en = r;
                --l, ++r;
            }
        };
        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(st, en - st + 1);
    }
};

int main() {
    string a = Solution().longestPalindrome("babad");
    assert(a == "bab" || a == "aba");
    assert(Solution().longestPalindrome("cbbd") == "bb");
    cout << "0005 OK" << endl;
    return 0;
}
