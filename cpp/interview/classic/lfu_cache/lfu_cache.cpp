// 手写 LFU Cache（O(1)）
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class LFUCache {
public:
    explicit LFUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = kv.find(key);
        if (it == kv.end()) return -1;
        bump(it);
        return it->second.it->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;
        auto it = kv.find(key);
        if (it != kv.end()) {
            it->second.it->val = value;
            bump(it);
            return;
        }
        if ((int)kv.size() >= cap) {
            auto& lst = buckets[minFreq];
            int evict = lst.back().key;
            lst.pop_back();
            kv.erase(evict);
        }
        buckets[1].push_front({key, value});
        kv[key] = {1, buckets[1].begin()};
        minFreq = 1;
    }

private:
    struct Node {
        int key;
        int val;
    };
    struct Entry {
        int freq;
        list<Node>::iterator it;
    };

    int cap;
    int minFreq = 0;
    unordered_map<int, Entry> kv;
    unordered_map<int, list<Node>> buckets;

    void bump(unordered_map<int, Entry>::iterator it) {
        int f = it->second.freq;
        Node node = *it->second.it;
        buckets[f].erase(it->second.it);
        if (buckets[f].empty()) {
            buckets.erase(f);
            if (minFreq == f) ++minFreq;
        }
        buckets[f + 1].push_front(node);
        it->second = {f + 1, buckets[f + 1].begin()};
    }
};

int main() {
    LFUCache c(2);
    c.put(1, 1);
    c.put(2, 2);
    assert(c.get(1) == 1);
    c.put(3, 3);
    assert(c.get(2) == -1);
    assert(c.get(3) == 3);
    c.put(4, 4);
    assert(c.get(1) == -1);
    assert(c.get(3) == 3);
    assert(c.get(4) == 4);
    LFUCache z(0);
    z.put(0, 0);
    assert(z.get(0) == -1);
    cout << "lfu_cache OK" << endl;
    return 0;
}
