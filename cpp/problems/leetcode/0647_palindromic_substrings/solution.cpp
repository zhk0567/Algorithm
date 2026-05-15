// LeetCode 647: Palindromic Substrings
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size(), ans = 0;
        auto expand = [&](int l, int r) {
            int cnt = 0;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ++cnt;
                --l;
                ++r;
            }
            return cnt;
        };
        for (int i = 0; i < n; ++i) {
            ans += expand(i, i);
            ans += expand(i, i + 1);
        }
        return ans;
    }
};

int main() {
    assert(Solution().countSubstrings("abc") == 3);
    assert(Solution().countSubstrings("aaa") == 6);
    assert(Solution().countSubstrings("") == 0);
    cout << "0647 OK" << endl;
    return 0;
}
