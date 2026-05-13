#include <bits/stdc++.h>
using namespace std;

optional<pair<int, int>> two_sum_sorted(const vector<int>& a, int t) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int s = a[lo] + a[hi];
        if (s == t) return {{lo, hi}};
        if (s < t)
            ++lo;
        else
            --hi;
    }
    return nullopt;
}

int max_area(const vector<int>& h) {
    int lo = 0, hi = (int)h.size() - 1, best = 0;
    while (lo < hi) {
        int w = hi - lo;
        best = max(best, w * min(h[lo], h[hi]));
        if (h[lo] < h[hi])
            ++lo;
        else
            --hi;
    }
    return best;
}

int main() {
    vector<int> a{1, 2, 4, 6, 10};
    auto p = two_sum_sorted(a, 8);
    assert(p && a[p->first] + a[p->second] == 8);
    assert(max_area({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
    cout << "two_pointers OK" << endl;
    return 0;
}
