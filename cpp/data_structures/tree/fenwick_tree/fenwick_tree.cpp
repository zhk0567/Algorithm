#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    explicit Fenwick(int n_) : n(n_), bit(n_ + 1, 0) {}

    void add(int index, long long delta) {
        for (int i = index + 1; i <= n; i += i & -i) bit[i] += delta;
    }

    long long prefix_sum(int index) const {
        long long s = 0;
        for (int i = index + 1; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

    long long range_sum(int l, int r) const {
        if (l == 0) return prefix_sum(r);
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

struct FenwickRUPQ {
    int n;
    Fenwick bit;
    explicit FenwickRUPQ(int n_) : n(n_), bit(n_ + 2) {}

    void range_add(int l, int r, long long v) {
        bit.add(l, v);
        if (r + 1 < n) bit.add(r + 1, -v);
    }

    long long point_query(int i) const { return bit.prefix_sum(i); }
};

int main() {
    Fenwick ft(5);
    vector<int> a{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) ft.add(i, a[i]);
    assert(ft.range_sum(1, 3) == 9);
    FenwickRUPQ rq(5);
    rq.range_add(1, 3, 10);
    assert(rq.point_query(0) == 0);
    assert(rq.point_query(2) == 10);
    cout << "Fenwick OK" << endl;
    return 0;
}
