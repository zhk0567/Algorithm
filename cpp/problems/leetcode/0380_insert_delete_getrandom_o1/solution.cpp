// LeetCode 380: Insert Delete GetRandom O(1)
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> idx;
    vector<int> vals;

public:
    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = (int)vals.size();
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val)) return false;
        int i = idx[val];
        int last = vals.back();
        vals[i] = last;
        idx[last] = i;
        vals.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

int main() {
    RandomizedSet s;
    assert(s.insert(1));
    assert(!s.insert(1));
    assert(!s.remove(2));
    assert(s.insert(2));
    s.remove(1);
    assert(s.getRandom() == 2);
    cout << "0380 OK" << endl;
    return 0;
}
