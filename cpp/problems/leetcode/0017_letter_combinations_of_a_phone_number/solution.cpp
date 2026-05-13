// LeetCode 17
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> mp{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };
        vector<string> res;
        string buf;
        function<void(int)> bt = [&](int i) {
            if (i == (int)digits.size()) {
                res.push_back(buf);
                return;
            }
            for (char ch : mp[digits[i]]) {
                buf.push_back(ch);
                bt(i + 1);
                buf.pop_back();
            }
        };
        bt(0);
        return res;
    }
};

int main() {
    auto out = Solution().letterCombinations("23");
    set<string> got(out.begin(), out.end());
    set<string> expect{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(got == expect);
    assert(Solution().letterCombinations("").empty());
    assert((Solution().letterCombinations("2") == vector<string>{"a", "b", "c"}));
    cout << "0017 OK" << endl;
    return 0;
}
