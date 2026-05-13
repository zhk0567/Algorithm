#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray_k(const vector<int>& nums, int k) {
    if (k <= 0 || k > (int)nums.size()) return 0;
    int s = accumulate(nums.begin(), nums.begin() + k, 0), best = s;
    for (int i = k; i < (int)nums.size(); ++i) {
        s += nums[i] - nums[i - k];
        best = max(best, s);
    }
    return best;
}

int length_longest_no_repeat(const string& s) {
    vector<int> last(256, -1);
    int lo = 0, best = 0;
    for (int hi = 0; hi < (int)s.size(); ++hi) {
        unsigned char ch = s[hi];
        if (last[ch] >= lo) lo = last[ch] + 1;
        last[ch] = hi;
        best = max(best, hi - lo + 1);
    }
    return best;
}

int main() {
    assert(max_sum_subarray_k({1, 2, 3, 4, 5}, 2) == 9);
    assert(length_longest_no_repeat("abcabcbb") == 3);
    cout << "sliding_window OK" << endl;
    return 0;
}
