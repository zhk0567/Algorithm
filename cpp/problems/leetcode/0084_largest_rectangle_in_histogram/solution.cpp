// LeetCode 84
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> h = heights;
        h.push_back(0);
        stack<int> st;
        int best = 0;
        for (int i = 0; i < (int)h.size(); ++i) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int top = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                best = max(best, h[top] * (i - left - 1));
            }
            st.push(i);
        }
        return best;
    }
};

int main() {
    vector<int> a{2, 1, 5, 6, 2, 3};
    assert(Solution().largestRectangleArea(a) == 10);
    vector<int> b{2, 4};
    assert(Solution().largestRectangleArea(b) == 4);
    vector<int> c{};
    assert(Solution().largestRectangleArea(c) == 0);
    cout << "0084 OK" << endl;
    return 0;
}
