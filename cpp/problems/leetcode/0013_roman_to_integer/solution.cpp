// LeetCode 13
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };
        int total = 0, n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            int v = mp[s[i]];
            if (i + 1 < n && v < mp[s[i + 1]])
                total -= v;
            else
                total += v;
        }
        return total;
    }
};

int main() {
    assert(Solution().romanToInt("III") == 3);
    assert(Solution().romanToInt("LVIII") == 58);
    assert(Solution().romanToInt("MCMXCIV") == 1994);
    cout << "0013 OK" << endl;
    return 0;
}
