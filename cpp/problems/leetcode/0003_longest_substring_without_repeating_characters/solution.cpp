// LeetCode 3
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int lo = 0, best = 0;
        for (int hi = 0; hi < (int)s.size(); ++hi) {
            unsigned char ch = s[hi];
            if (last[ch] >= lo) lo = last[ch] + 1;
            last[ch] = hi;
            best = max(best, hi - lo + 1);
        }
        return best;
    }
};

int main() {
    assert(Solution().lengthOfLongestSubstring("abcabcbb") == 3);
    assert(Solution().lengthOfLongestSubstring("bbbbb") == 1);
    assert(Solution().lengthOfLongestSubstring("pwwkew") == 3);
    cout << "0003 OK" << endl;
    return 0;
}
