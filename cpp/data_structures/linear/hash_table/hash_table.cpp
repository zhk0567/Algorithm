#include <bits/stdc++.h>
using namespace std;

struct HashTable {
    static constexpr double LOAD_MAX = 0.75;
    struct Node {
        int key;
        string val;
        Node* next;
        Node(int k, string v, Node* n) : key(k), val(move(v)), next(n) {}
    };
    vector<Node*> buckets;
    int n = 0, m = 8;

    HashTable() { buckets.assign(m, nullptr); }

    size_t h(int key) const { return (size_t)(key % m + m) % (size_t)m; }

    void rehash(int new_m) {
        vector<Node*> old = buckets;
        int old_m = m;
        m = max(1, new_m);
        n = 0;
        buckets.assign(m, nullptr);
        for (int i = 0; i < old_m; ++i) {
            Node* p = old[i];
            while (p) {
                insert(p->key, p->val);
                Node* nx = p->next;
                delete p;
                p = nx;
            }
        }
    }

    void insert(int key, string val) {
        if ((n + 1) > (int)(LOAD_MAX * m)) rehash(m * 2);
        size_t bi = h(key);
        for (Node* p = buckets[bi]; p; p = p->next) {
            if (p->key == key) {
                p->val = move(val);
                return;
            }
        }
        buckets[bi] = new Node(key, move(val), buckets[bi]);
        ++n;
    }

    string get(int key) const {
        for (Node* p = buckets[h(key)]; p; p = p->next)
            if (p->key == key) return p->val;
        throw out_of_range("get");
    }

    void erase(int key) {
        size_t bi = h(key);
        Node* p = buckets[bi];
        if (!p) throw out_of_range("erase");
        if (p->key == key) {
            buckets[bi] = p->next;
            delete p;
            --n;
            return;
        }
        while (p->next) {
            if (p->next->key == key) {
                Node* t = p->next;
                p->next = t->next;
                delete t;
                --n;
                return;
            }
            p = p->next;
        }
        throw out_of_range("erase");
    }
};

int main() {
    HashTable ht;
    ht.insert(1, "a");
    ht.insert(1, "c");
    assert(ht.get(1) == "c");
    ht.erase(1);
    try {
        ht.get(1);
        assert(false);
    } catch (...) {
    }
    cout << "HashTable OK" << endl;
    return 0;
}
