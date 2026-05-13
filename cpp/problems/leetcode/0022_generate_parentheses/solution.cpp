// LeetCode 22
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        function<void(int, int)> bt = [&](int open, int close) {
            if ((int)cur.size() == 2 * n) {
                res.push_back(cur);
                return;
            }
            if (open < n) {
                cur.push_back('(');
                bt(open + 1, close);
                cur.pop_back();
            }
            if (close < open) {
                cur.push_back(')');
                bt(open, close + 1);
                cur.pop_back();
            }
        };
        bt(0, 0);
        return res;
    }
};

int main() {
    auto v = Solution().generateParenthesis(3);
    set<string> st(v.begin(), v.end());
    assert(st == set<string>{"((()))", "(()())", "(())()", "()(())", "()()()"});
    assert(Solution().generateParenthesis(1) == vector<string>{"()"});
    cout << "0022 OK" << endl;
    return 0;
}
