#include <bits/stdc++.h>
using namespace std;

int activity_selection(vector<pair<int, int>> iv) {
    sort(iv.begin(), iv.end(), [](auto& a, auto& b) { return a.second < b.second; });
    int cnt = 0, last = INT_MIN / 2;
    for (auto [s, e] : iv)
        if (s >= last) {
            ++cnt;
            last = e;
        }
    return cnt;
}

double fractional_knapsack(vector<pair<int, int>> items, int cap) {
    vector<tuple<double, int, int>> r;
    for (auto [w, v] : items)
        if (w > 0) r.push_back({(double)v / w, w, v});
    sort(r.begin(), r.end(), greater<tuple<double, int, int>>());
    double rem = cap, tot = 0;
    for (auto [rv, w, v] : r) {
        if (rem <= 0) break;
        double take = min(rem, (double)w);
        tot += take * ((double)v / w);
        rem -= take;
    }
    return tot;
}

int main() {
    assert(activity_selection({{1, 2}, {3, 4}, {5, 6}, {7, 8}}) == 4);
    assert(abs(fractional_knapsack({{10, 60}, {20, 100}, {30, 120}}, 50) - 240.0) < 1e-9);
    cout << "greedy OK" << endl;
    return 0;
}
