// LeetCode 28
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = (int)needle.size();
        vector<int> nxt(m, 0);
        for (int i = 1, k = 0; i < m; ++i) {
            while (k > 0 && needle[k] != needle[i]) k = nxt[k - 1];
            if (needle[k] == needle[i]) ++k;
            nxt[i] = k;
        }
        int k = 0;
        for (int i = 0; i < (int)haystack.size(); ++i) {
            while (k > 0 && needle[k] != haystack[i]) k = nxt[k - 1];
            if (needle[k] == haystack[i]) ++k;
            if (k == m) return i - m + 1;
        }
        return -1;
    }
};

int main() {
    assert(Solution().strStr("sadbutsad", "sad") == 0);
    assert(Solution().strStr("leetcode", "leeto") == -1);
    assert(Solution().strStr("aaa", "aa") == 0);
    assert(Solution().strStr("", "") == 0);
    cout << "0028 OK" << endl;
    return 0;
}
