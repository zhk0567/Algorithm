// LeetCode 76
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.empty()) return "";
        unordered_map<char, int> need, have;
        for (char c : t) ++need[c];
        int need_kinds = (int)need.size(), match = 0;
        int best_l = 0, best_len = INT_MAX, l = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            char c = s[r];
            ++have[c];
            if (need.count(c) && have[c] == need[c]) ++match;
            while (match == need_kinds) {
                if (r - l + 1 < best_len) {
                    best_l = l;
                    best_len = r - l + 1;
                }
                char lc = s[l];
                --have[lc];
                if (need.count(lc) && have[lc] < need[lc]) --match;
                ++l;
            }
        }
        return best_len == INT_MAX ? "" : s.substr(best_l, best_len);
    }
};

int main() {
    assert(Solution().minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(Solution().minWindow("a", "a") == "a");
    assert(Solution().minWindow("a", "aa") == "");
    cout << "0076 OK" << endl;
    return 0;
}
