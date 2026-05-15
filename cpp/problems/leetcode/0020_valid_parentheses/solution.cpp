// LeetCode 20
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        unordered_map<char, char> p{{')', '('}, {']', '['}, {'}', '{'}};
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push_back(ch);
            else {
                if (st.empty() || st.back() != p[ch]) return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};

int main() {
    assert(Solution().isValid("()[]{}"));
    assert(!Solution().isValid("(]"));
    cout << "0020 OK" << endl;
    return 0;
}
