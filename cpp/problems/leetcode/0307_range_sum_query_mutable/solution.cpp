// LeetCode 307: Range Sum Query - Mutable
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class NumArray {
    vector<int> nums;
    vector<int> bit;
    int n;

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) bit[i] += delta;
    }

    int prefix(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

public:
    explicit NumArray(vector<int>& arr) {
        nums = arr;
        n = (int)nums.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) add(i + 1, nums[i]);
    }

    void update(int index, int val) {
        int d = val - nums[index];
        nums[index] = val;
        add(index + 1, d);
    }

    int sumRange(int left, int right) { return prefix(right + 1) - prefix(left); }
};

int main() {
    vector<int> a{1, 3, 5};
    NumArray na(a);
    assert(na.sumRange(0, 2) == 9);
    na.update(1, 2);
    assert(na.sumRange(0, 2) == 8);
    vector<int> b{0};
    NumArray na2(b);
    assert(na2.sumRange(0, 0) == 0);
    na2.update(0, 5);
    assert(na2.sumRange(0, 0) == 5);
    cout << "0307 OK" << endl;
    return 0;
}
