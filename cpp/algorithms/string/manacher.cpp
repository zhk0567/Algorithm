// Manacher 最长回文子串
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

string longest_palindrome(const string& s) {
    if (s.empty()) return "";
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    int n = (int)t.size();
    vector<int> p(n, 0);
    int c = 0, r = 0, best_i = 0;
    for (int i = 1; i < n; ++i) {
        int mirror = 2 * c - i;
        if (i < r) p[i] = min(r - i, p[mirror]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
               t[i - p[i] - 1] == t[i + p[i] + 1])
            ++p[i];
        if (i + p[i] > r) c = i, r = i + p[i];
        if (p[i] > p[best_i]) best_i = i;
    }
    int start = (best_i - p[best_i]) / 2;
    return s.substr(start, p[best_i]);
}

int main() {
    string a = longest_palindrome("babad");
    assert(a == "bab" || a == "aba");
    assert(longest_palindrome("cbbd") == "bb");
    assert(longest_palindrome("a") == "a");
    cout << "manacher OK" << endl;
    return 0;
}
