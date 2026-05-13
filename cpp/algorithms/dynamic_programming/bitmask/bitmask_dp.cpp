#include <bits/stdc++.h>
using namespace std;

const long long INF = (long long)4e18;

long long tsp(const vector<vector<long long>>& dist) {
    int n = (int)dist.size();
    int full = (1 << n) - 1;
    vector<vector<long long>> dp(1 << n, vector<long long>(n, INF));
    dp[1][0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
        for (int u = 0; u < n; ++u) {
            if (!((mask >> u) & 1)) continue;
            if (dp[mask][u] >= INF / 4) continue;
            for (int v = 0; v < n; ++v) {
                if ((mask >> v) & 1) continue;
                int nmask = mask | (1 << v);
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + dist[u][v]);
            }
        }
    long long best = INF;
    for (int u = 1; u < n; ++u) best = min(best, dp[full][u] + dist[u][0]);
    return best;
}

int main() {
    const long long X = (long long)1e9;
    vector<vector<long long>> d = {{0, 2, 9, X}, {1, 0, 6, 4}, {15, 7, 0, 8}, {6, 3, 12, 0}};
    assert(tsp(d) == 21);
    cout << "bitmask_dp OK" << endl;
    return 0;
}
