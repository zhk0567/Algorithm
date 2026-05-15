#include <alg_std.hpp>
#include <cassert>
using namespace std;

vector<int> build_lps(const string& pat) {
    int m = (int)pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

vector<int> kmp_search(const string& text, const string& pat) {
    vector<int> res;
    if (pat.empty()) return res;
    vector<int> lps = build_lps(pat);
    int i = 0, j = 0, n = (int)text.size(), m = (int)pat.size();
    while (i < n) {
        if (text[i] == pat[j]) {
            ++i, ++j;
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else if (j)
            j = lps[j - 1];
        else
            ++i;
    }
    return res;
}

int main() {
    auto lps = build_lps("ababaca");
    assert(lps == vector<int>({0, 0, 1, 2, 3, 0, 1}));
    assert(kmp_search("ababcababa", "aba") == vector<int>({0, 5, 7}));
    cout << "string OK" << endl;
    return 0;
}
