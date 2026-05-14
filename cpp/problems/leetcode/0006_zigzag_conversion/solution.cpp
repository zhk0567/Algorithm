// LeetCode 6
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;
        vector<string> rows(numRows);
        int i = 0, step = 1;
        for (char ch : s) {
            rows[i].push_back(ch);
            if (i == 0)
                step = 1;
            else if (i == numRows - 1)
                step = -1;
            i += step;
        }
        string out;
        for (auto& r : rows) out += r;
        return out;
    }
};

int main() {
    assert(Solution().convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(Solution().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(Solution().convert("A", 1) == "A");
    cout << "0006 OK" << endl;
    return 0;
}
