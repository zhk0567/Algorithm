#include <alg_std.hpp>
#include <cassert>
using namespace std;

struct SegTree {
    int n;
    vector<long long> sum, lazy;
    SegTree(const vector<int>& a) {
        n = (int)a.size();
        sum.assign(4 * max(1, n), 0);
        lazy.assign(4 * max(1, n), 0);
        if (n) build(1, 0, n - 1, a);
    }

    void build(int idx, int l, int r, const vector<int>& a) {
        if (l == r) {
            sum[idx] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(idx * 2, l, m, a);
        build(idx * 2 + 1, m + 1, r, a);
        sum[idx] = sum[idx * 2] + sum[idx * 2 + 1];
    }

    void push(int idx, int l, int r) {
        if (!lazy[idx] || l == r) return;
        int m = (l + r) / 2;
        for (int c : {idx * 2, idx * 2 + 1}) {
            lazy[c] += lazy[idx];
        }
        sum[idx * 2] += lazy[idx] * (m - l + 1);
        sum[idx * 2 + 1] += lazy[idx] * (r - m);
        lazy[idx] = 0;
    }

    void range_add(int idx, int l, int r, int ql, int qr, long long v) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            lazy[idx] += v;
            sum[idx] += v * (r - l + 1);
            return;
        }
        push(idx, l, r);
        int m = (l + r) / 2;
        range_add(idx * 2, l, m, ql, qr, v);
        range_add(idx * 2 + 1, m + 1, r, ql, qr, v);
        sum[idx] = sum[idx * 2] + sum[idx * 2 + 1];
    }

    long long range_sum(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return sum[idx];
        push(idx, l, r);
        int m = (l + r) / 2;
        return range_sum(idx * 2, l, m, ql, qr) + range_sum(idx * 2 + 1, m + 1, r, ql, qr);
    }

    void range_add(int ql, int qr, long long v) { range_add(1, 0, n - 1, ql, qr, v); }

    long long range_sum(int ql, int qr) { return range_sum(1, 0, n - 1, ql, qr); }
};

int main() {
    SegTree st(vector<int>{1, 2, 3, 4, 5});
    assert(st.range_sum(1, 3) == 9);
    st.range_add(1, 3, 10);
    long long s = st.range_sum(0, 4);
    assert(s == 1 + 12 + 13 + 14 + 5);
    cout << "SegmentTree OK" << endl;
    return 0;
}
