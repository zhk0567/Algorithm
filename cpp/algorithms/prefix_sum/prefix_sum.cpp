#include <bits/stdc++.h>
using namespace std;

vector<int> build_prefix(const vector<int>& a) {
    vector<int> p(a.size() + 1, 0);
    for (int i = 0; i < (int)a.size(); ++i) p[i + 1] = p[i] + a[i];
    return p;
}

int range_sum(const vector<int>& p, int l, int r) { return p[r + 1] - p[l]; }

struct DifferenceArray {
    int n;
    vector<int> d;
    explicit DifferenceArray(int n_) : n(n_), d(n_ + 1, 0) {}
    void range_add(int l, int r, int v) {
        d[l] += v;
        if (r + 1 < (int)d.size()) d[r + 1] -= v;
    }
    vector<int> to_array() const {
        vector<int> a;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            a.push_back(s);
        }
        return a;
    }
};

int main() {
    vector<int> a{1, 2, 3, 4};
    auto p = build_prefix(a);
    assert(range_sum(p, 1, 2) == 5);
    DifferenceArray da(5);
    da.range_add(1, 3, 5);
    assert(da.to_array() == vector<int>({0, 5, 5, 5, 0}));
    cout << "prefix_sum OK" << endl;
    return 0;
}
