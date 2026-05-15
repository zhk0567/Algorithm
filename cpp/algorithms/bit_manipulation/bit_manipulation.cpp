#include <alg_std.hpp>
#include <cassert>
using namespace std;

int lowbit(int x) { return x & -x; }

int popcount(int x) {
    int c = 0;
    while (x) {
        x &= x - 1;
        ++c;
    }
    return c;
}

vector<int> subsets_of_mask(int m) {
    vector<int> o;
    for (int s = m;; s = (s - 1) & m) {
        o.push_back(s);
        if (s == 0) break;
    }
    return o;
}

int main() {
    assert(lowbit(12) == 4);
    assert(popcount(0b1011) == 3);
    auto ss = subsets_of_mask(0b101);
    set<int> st(ss.begin(), ss.end());
    assert(st == set<int>({0b101, 0b100, 0b001, 0}));
    cout << "bit_manipulation OK" << endl;
    return 0;
}
