// LeetCode 146
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = idx.find(key);
        if (it == idx.end()) return -1;
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = idx.find(key);
        if (it != idx.end()) {
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }
        if ((int)order.size() == cap) {
            idx.erase(order.back().first);
            order.pop_back();
        }
        order.push_front({key, value});
        idx[key] = order.begin();
    }

private:
    int cap;
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> idx;
};

int main() {
    LRUCache c(2);
    c.put(1, 1);
    c.put(2, 2);
    assert(c.get(1) == 1);
    c.put(3, 3);
    assert(c.get(2) == -1);
    c.put(4, 4);
    assert(c.get(1) == -1);
    assert(c.get(3) == 3);
    assert(c.get(4) == 4);
    cout << "0146 OK" << endl;
    return 0;
}
