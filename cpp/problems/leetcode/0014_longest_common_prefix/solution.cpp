// LeetCode 14
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        const string& base = strs[0];
        for (size_t i = 0; i < base.size(); ++i) {
            char ch = base[i];
            for (size_t k = 1; k < strs.size(); ++k) {
                if (i >= strs[k].size() || strs[k][i] != ch)
                    return base.substr(0, i);
            }
        }
        return base;
    }
};

int main() {
    vector<string> a{"flower", "flow", "flight"};
    assert(Solution().longestCommonPrefix(a) == "fl");
    vector<string> b{"dog", "racecar", "car"};
    assert(Solution().longestCommonPrefix(b) == "");
    vector<string> c{""};
    assert(Solution().longestCommonPrefix(c) == "");
    cout << "0014 OK" << endl;
    return 0;
}
