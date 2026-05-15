#include <alg_std.hpp>
#include <cassert>
using namespace std;

int linear_search(const vector<int>& a, int x) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] == x) return i;
    return -1;
}

int binary_search_vec(const vector<int>& a, int x) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int lower_bound_vec(const vector<int>& a, int x) {
    int lo = 0, hi = (int)a.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int upper_bound_vec(const vector<int>& a, int x) {
    int lo = 0, hi = (int)a.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] <= x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int search_rotated(const vector<int>& a, int t) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == t) return mid;
        if (a[lo] <= a[mid]) {
            if (a[lo] <= t && t < a[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        } else {
            if (a[mid] < t && t <= a[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> a{1, 3, 3, 5, 7};
    assert(linear_search(a, 5) == 3);
    assert(binary_search_vec(vector<int>{1, 2, 4, 8}, 4) == 2);
    assert(lower_bound_vec(a, 3) == 1 && upper_bound_vec(a, 3) == 3);
    vector<int> rot{4, 5, 6, 7, 0, 1, 2};
    assert(search_rotated(rot, 0) == 4);
    cout << "searching OK" << endl;
    return 0;
}
