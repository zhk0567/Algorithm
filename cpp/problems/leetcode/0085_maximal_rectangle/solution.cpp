// LeetCode 85
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

static int largestInHist(vector<int> h) {
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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = (int)matrix[0].size();
        vector<int> heights(n, 0);
        int best = 0;
        for (auto& row : matrix) {
            for (int j = 0; j < n; ++j)
                heights[j] = row[j] == '1' ? heights[j] + 1 : 0;
            best = max(best, largestInHist(heights));
        }
        return best;
    }
};

int main() {
    vector<vector<char>> m{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    assert(Solution().maximalRectangle(m) == 6);
    vector<vector<char>> e{};
    assert(Solution().maximalRectangle(e) == 0);
    vector<vector<char>> z{{'0'}};
    assert(Solution().maximalRectangle(z) == 0);
    vector<vector<char>> o{{'1'}};
    assert(Solution().maximalRectangle(o) == 1);
    cout << "0085 OK" << endl;
    return 0;
}
