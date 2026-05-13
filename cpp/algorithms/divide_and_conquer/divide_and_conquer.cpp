#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long base, long long exp, long long mod) {
    if (mod == 1) return 0;
    long long res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

long long cross_sum(const vector<int>& a, int lo, int mid, int hi) {
    long long left_best = a[mid], left_sum = a[mid];
    for (int i = mid - 1; i >= lo; --i) {
        left_sum += a[i];
        left_best = max(left_best, left_sum);
    }
    long long right_best = a[mid + 1], right_sum = a[mid + 1];
    for (int i = mid + 2; i <= hi; ++i) {
        right_sum += a[i];
        right_best = max(right_best, right_sum);
    }
    return left_best + right_best;
}

long long max_subarray_dc(const vector<int>& a, int lo, int hi) {
    if (lo == hi) return a[lo];
    int mid = (lo + hi) / 2;
    return max({max_subarray_dc(a, lo, mid), max_subarray_dc(a, mid + 1, hi), cross_sum(a, lo, mid, hi)});
}

int main() {
    assert(mod_pow(2, 10, 1000) == 24);
    assert(mod_pow(3, 0, 7) == 1);
    vector<int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(max_subarray_dc(a, 0, (int)a.size() - 1) == 6);
    cout << "divide_and_conquer OK" << endl;
    return 0;
}
