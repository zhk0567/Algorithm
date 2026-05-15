#include <alg_std.hpp>
#include <cassert>
using namespace std;

vector<int> bubble_sort(vector<int> a) {
    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        bool sw = false;
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sw = true;
            }
        if (!sw) break;
    }
    return a;
}

vector<int> merge_vec(const vector<int>& L, const vector<int>& R) {
    vector<int> o;
    int i = 0, j = 0;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j])
            o.push_back(L[i++]);
        else
            o.push_back(R[j++]);
    }
    while (i < (int)L.size()) o.push_back(L[i++]);
    while (j < (int)R.size()) o.push_back(R[j++]);
    return o;
}

vector<int> merge_sort(const vector<int>& a) {
    if (a.size() <= 1) return a;
    int m = (int)a.size() / 2;
    return merge_vec(merge_sort(vector<int>(a.begin(), a.begin() + m)),
                     merge_sort(vector<int>(a.begin() + m, a.end())));
}

int partition_vec(vector<int>& a, int lo, int hi) {
    int pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; ++j)
        if (a[j] <= pivot) swap(a[i++], a[j]);
    swap(a[i], a[hi]);
    return i;
}

void quick_sort_inplace(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;
    int p = partition_vec(a, lo, hi);
    quick_sort_inplace(a, lo, p - 1);
    quick_sort_inplace(a, p + 1, hi);
}

void sift_down(vector<int>& a, int start, int end) {
    while (true) {
        int l = 2 * start + 1, r = l + 1, m = start;
        if (l < end && a[l] > a[m]) m = l;
        if (r < end && a[r] > a[m]) m = r;
        if (m == start) break;
        swap(a[start], a[m]);
        start = m;
    }
}

vector<int> heap_sort(vector<int> a) {
    int n = (int)a.size();
    for (int i = n / 2 - 1; i >= 0; --i) sift_down(a, i, n);
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);
        sift_down(a, 0, end);
    }
    return a;
}

vector<int> counting_sort_nonneg(const vector<int>& a) {
    if (a.empty()) return {};
    int mx = *max_element(a.begin(), a.end());
    vector<int> c(mx + 1, 0);
    for (int x : a) ++c[x];
    vector<int> o;
    for (int i = 0; i <= mx; ++i)
        o.insert(o.end(), c[i], i);
    return o;
}

vector<int> radix_sort_nonneg(vector<int> a) {
    if (a.empty()) return {};
    int mx = *max_element(a.begin(), a.end());
    for (long long exp = 1; mx / exp > 0; exp *= 10) {
        array<vector<int>, 10> buckets;
        for (int x : a) buckets[(x / exp) % 10].push_back(x);
        a.clear();
        for (auto& b : buckets) a.insert(a.end(), b.begin(), b.end());
    }
    return a;
}

vector<double> bucket_sort_unit(vector<double> a) {
    int n = (int)a.size();
    if (n <= 1) return a;
    vector<vector<double>> buckets(n);
    for (double x : a) {
        int bi = min((int)(n * x), n - 1);
        buckets[bi].push_back(x);
    }
    vector<double> o;
    for (auto& b : buckets) {
        sort(b.begin(), b.end());
        o.insert(o.end(), b.begin(), b.end());
    }
    return o;
}

int main() {
    vector<int> sample{5, 2, 8, 1, 9, 3};
    auto sorted = sample;
    sort(sorted.begin(), sorted.end());
    assert(bubble_sort(sample) == sorted);
    assert(merge_sort(sample) == sorted);
    auto qs = sample;
    quick_sort_inplace(qs, 0, (int)qs.size() - 1);
    assert(qs == sorted);
    assert(heap_sort(sample) == sorted);
    assert(counting_sort_nonneg({3, 0, 2, 2, 1}) == vector<int>({0, 1, 2, 2, 3}));
    assert(radix_sort_nonneg({170, 45, 75, 90, 2, 802}) == vector<int>({2, 45, 75, 90, 170, 802}));
    auto bu = bucket_sort_unit({0.9, 0.1, 0.4, 0.35});
    assert(bu == vector<double>({0.1, 0.35, 0.4, 0.9}));
    cout << "sorting OK" << endl;
    return 0;
}
