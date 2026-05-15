// LeetCode 210: Course Schedule II
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& e : prerequisites) {
            g[e[1]].push_back(e[0]);
            ++indeg[e[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            order.push_back(x);
            for (int y : g[x])
                if (--indeg[y] == 0) q.push(y);
        }
        return (int)order.size() == numCourses ? order : vector<int>{};
    }
};

int main() {
    vector<vector<int>> p1{{1, 0}};
    assert(Solution().findOrder(2, p1) == vector<int>({0, 1}));
    vector<vector<int>> p2{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    assert(Solution().findOrder(4, p2) == vector<int>({0, 1, 2, 3}));
    vector<vector<int>> p3{{1, 0}, {0, 1}};
    assert(Solution().findOrder(2, p3).empty());
    cout << "0210 OK" << endl;
    return 0;
}
