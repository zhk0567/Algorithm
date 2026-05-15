// LeetCode 743: Network Delay Time
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : times) adj[e[0] - 1].push_back({e[1] - 1, e[2]});
        const int inf = 1e9;
        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k - 1});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                int nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        int mx = *max_element(dist.begin(), dist.end());
        return mx < inf ? mx : -1;
    }
};

int main() {
    vector<vector<int>> t1{{2, 1, 1}, {1, 3, 1}, {2, 3, 1}};
    assert(Solution().networkDelayTime(t1, 3, 2) == 1);
    assert(Solution().networkDelayTime(t1, 4, 2) == -1);
    vector<vector<int>> t2{{1, 2, 1}};
    assert(Solution().networkDelayTime(t2, 2, 1) == 1);
    assert(Solution().networkDelayTime(t2, 2, 2) == -1);
    cout << "0743 OK" << endl;
    return 0;
}
