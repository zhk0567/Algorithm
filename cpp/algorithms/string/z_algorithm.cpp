// Z 函数（扩展 KMP）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

vector<int> z_function(const string& s) {
    int n = (int)s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> z_search(const string& text, const string& pat) {
    vector<int> res;
    if (pat.empty()) return res;
    if ((int)pat.size() > (int)text.size()) return res;
    string combined = pat + '\0' + text;
    vector<int> z = z_function(combined);
    int m = (int)pat.size();
    for (int i = m + 1; i < (int)combined.size(); ++i) {
        if (z[i] == m) res.push_back(i - m - 1);
    }
    return res;
}

int main() {
    assert(z_function("aaabaab") == vector<int>({0, 2, 1, 0, 2, 1, 0}));
    assert(z_search("ababa", "aba") == vector<int>({0, 2}));
    cout << "z_algorithm OK" << endl;
    return 0;
}
