// LeetCode 96
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<long long> g(n + 1, 0);
        g[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                g[i] += g[j - 1] * g[i - j];
        return (int)g[n];
    }
};

int main() {
    assert(Solution().numTrees(3) == 5);
    assert(Solution().numTrees(1) == 1);
    assert(Solution().numTrees(0) == 1);
    assert(Solution().numTrees(5) == 42);
    cout << "0096 OK" << endl;
    return 0;
}
