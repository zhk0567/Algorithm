// LeetCode 32
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st{-1};
        int best = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                st.push_back(i);
            } else {
                st.pop_back();
                if (st.empty())
                    st.push_back(i);
                else
                    best = max(best, i - st.back());
            }
        }
        return best;
    }
};

int main() {
    assert(Solution().longestValidParentheses("(()") == 2);
    assert(Solution().longestValidParentheses(")()())") == 4);
    assert(Solution().longestValidParentheses("") == 0);
    cout << "0032 OK" << endl;
    return 0;
}
