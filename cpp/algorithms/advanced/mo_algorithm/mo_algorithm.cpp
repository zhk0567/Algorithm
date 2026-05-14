// 莫队：区间不同元素个数（与 Python 版同构）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

vector<int> mo_distinct_count(const vector<int>& arr, const vector<pair<int, int>>& queries) {
    const int n = static_cast<int>(arr.size());
    const int qn = static_cast<int>(queries.size());
    if (qn == 0) return {};
    const int b = max(1, static_cast<int>(sqrt(n)));
    vector<int> order(qn);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        int li = queries[i].first / b, lj = queries[j].first / b;
        if (li != lj) return li < lj;
        if (li & 1) return queries[i].second > queries[j].second;
        return queries[i].second < queries[j].second;
    });
    unordered_map<int, int> cnt;
    int cur = 0;
    vector<int> out(qn);
    auto add = [&](int i) {
        int x = arr[i];
        if (++cnt[x] == 1) ++cur;
    };
    auto remove = [&](int i) {
        int x = arr[i];
        if (--cnt[x] == 0) --cur;
    };
    int L = 0, R = -1;
    for (int qi : order) {
        int l = queries[qi].first, r = queries[qi].second;
        while (R < r) add(++R);
        while (R > r) remove(R--);
        while (L < l) remove(L++);
        while (L > l) add(--L);
        out[qi] = cur;
    }
    return out;
}

int main() {
    vector<int> a{1, 2, 1, 3, 2, 3, 3};
    vector<pair<int, int>> qs{{0, 6}, {1, 4}, {4, 4}};
    auto ans = mo_distinct_count(a, qs);
    assert(ans.size() == 3 && ans[0] == 3 && ans[1] == 3 && ans[2] == 1);
    cout << "mo_algorithm OK" << endl;
    return 0;
}
