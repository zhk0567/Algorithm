// LeetCode 207
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& e : prerequisites) {
            g[e[1]].push_back(e[0]);
            ++indeg[e[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);
        int done = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ++done;
            for (int y : g[x])
                if (--indeg[y] == 0) q.push(y);
        }
        return done == numCourses;
    }
};

int main() {
    vector<vector<int>> a{{1, 0}};
    assert(Solution().canFinish(2, a));
    vector<vector<int>> b{{1, 0}, {0, 1}};
    assert(!Solution().canFinish(2, b));
    vector<vector<int>> c{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    assert(Solution().canFinish(4, c));
    cout << "0207 OK" << endl;
    return 0;
}
