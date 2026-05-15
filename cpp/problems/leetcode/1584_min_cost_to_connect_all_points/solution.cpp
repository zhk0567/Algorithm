// LeetCode 1584: Min Cost to Connect All Points
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        if (n <= 1) return 0;
        vector<long long> dist(n, (long long)4e18);
        vector<char> vis(n, 0);
        dist[0] = 0;
        long long total = 0;
        auto manhattan = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        for (int k = 0; k < n; ++k) {
            int u = -1;
            long long best = (long long)4e18;
            for (int i = 0; i < n; ++i)
                if (!vis[i] && dist[i] < best) {
                    best = dist[i];
                    u = i;
                }
            vis[u] = 1;
            total += best;
            for (int v = 0; v < n; ++v)
                if (!vis[v]) {
                    int w = manhattan(u, v);
                    if (w < dist[v]) dist[v] = w;
                }
        }
        return (int)total;
    }
};

int main() {
    vector<vector<int>> p1{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    assert(Solution().minCostConnectPoints(p1) == 20);
    vector<vector<int>> p2{{3, 12}, {-2, 5}, {-4, 1}};
    assert(Solution().minCostConnectPoints(p2) == 18);
    vector<vector<int>> p3{{0, 0}};
    assert(Solution().minCostConnectPoints(p3) == 0);
    cout << "1584 OK" << endl;
    return 0;
}
