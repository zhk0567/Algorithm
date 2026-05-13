#include <bits/stdc++.h>
using namespace std;

struct LRUCache {
    int cap;
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    explicit LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        lst.splice(lst.begin(), lst, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            lst.erase(it->second);
            mp.erase(it);
        } else if ((int)mp.size() >= cap) {
            int lk = lst.back().first;
            lst.pop_back();
            mp.erase(lk);
        }
        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};

int main() {
    LRUCache c(2);
    c.put(1, 1);
    c.put(2, 2);
    assert(c.get(1) == 1);
    c.put(3, 3);
    assert(c.get(2) == -1);
    c.put(4, 4);
    assert(c.get(1) == -1 && c.get(3) == 3);
    cout << "LRUCache OK" << endl;
    return 0;
}
