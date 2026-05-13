#include <bits/stdc++.h>
using namespace std;

struct SqrtDecomposition {
    vector<int> a;
    vector<int> blk;
    int n, b;
    explicit SqrtDecomposition(vector<int> arr) : a(move(arr)) {
        n = (int)a.size();
        b = max(1, (int)sqrt(n));
        for (int i = 0; i < n; i += b) {
            int s = 0;
            for (int j = i; j < min(n, i + b); ++j) s += a[j];
            blk.push_back(s);
        }
    }
    int id(int i) const { return i / b; }
    void point_add(int i, int delta) {
        a[i] += delta;
        blk[id(i)] += delta;
    }
    int range_sum(int l, int r) const {
        int s = 0;
        if (id(l) == id(r)) {
            for (int i = l; i <= r; ++i) s += a[i];
            return s;
        }
        while (l <= r && l % b != 0) s += a[l++];
        while (l <= r && (r + 1) % b != 0) s += a[r--];
        while (l <= r) {
            s += blk[id(l)];
            l += b;
        }
        return s;
    }
};

int main() {
    SqrtDecomposition sd({1, 2, 3, 4, 5});
    assert(sd.range_sum(0, 4) == 15);
    sd.point_add(2, 10);
    assert(sd.range_sum(0, 4) == 25);
    assert(sd.range_sum(1, 3) == 2 + 13 + 4);
    cout << "advanced OK" << endl;
    return 0;
}
