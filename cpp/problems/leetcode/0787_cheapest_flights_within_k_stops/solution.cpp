// LeetCode 787: Cheapest Flights Within K Stops
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = 1e9;
        vector<int> dist(n, inf);
        dist[src] = 0;
        for (int round = 0; round <= k; ++round) {
            vector<int> nxt = dist;
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != inf) nxt[v] = min(nxt[v], dist[u] + w);
            }
            dist = move(nxt);
        }
        return dist[dst] < inf ? dist[dst] : -1;
    }
};

int main() {
    vector<vector<int>> f{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    assert(Solution().findCheapestPrice(3, f, 0, 2, 1) == 200);
    assert(Solution().findCheapestPrice(3, f, 0, 2, 0) == 500);
    vector<vector<int>> f2{{0, 1, 100}, {1, 2, 100}};
    assert(Solution().findCheapestPrice(3, f2, 0, 2, 1) == 200);
    cout << "0787 OK" << endl;
    return 0;
}
