#include <bits/stdc++.h>
using namespace std;

constexpr int MAXL = 16;
constexpr double P = 0.5;

struct Node {
    int key;
    vector<Node*> fwd;
    explicit Node(int k, int lv) : key(k), fwd(lv, nullptr) {}
};

struct SkipList {
    const int NEG = INT_MIN / 4;
    Node* head;
    int level = 1;
    mt19937 rng{12345};

    SkipList() : head(new Node(NEG, MAXL)) {}

    int random_level() {
        int lv = 1;
        uniform_real_distribution<double> u(0, 1);
        while (u(rng) < P && lv < MAXL) ++lv;
        return lv;
    }

    bool search(int key) {
        Node* x = head;
        for (int i = level - 1; i >= 0; --i) {
            while (x->fwd[i] && x->fwd[i]->key < key) x = x->fwd[i];
        }
        x = x->fwd[0];
        return x && x->key == key;
    }

    void insert(int key) {
        array<Node*, MAXL> upd{};
        fill(upd.begin(), upd.end(), head);
        Node* x = head;
        for (int i = level - 1; i >= 0; --i) {
            while (x->fwd[i] && x->fwd[i]->key < key) x = x->fwd[i];
            upd[i] = x;
        }
        x = x->fwd[0];
        if (x && x->key == key) return;
        int lv = random_level();
        if (lv > level) {
            for (int i = level; i < lv; ++i) upd[i] = head;
            level = lv;
        }
        Node* nd = new Node(key, lv);
        for (int i = 0; i < lv; ++i) {
            nd->fwd[i] = upd[i]->fwd[i];
            upd[i]->fwd[i] = nd;
        }
    }

    bool erase(int key) {
        array<Node*, MAXL> upd{};
        fill(upd.begin(), upd.end(), head);
        Node* x = head;
        for (int i = level - 1; i >= 0; --i) {
            while (x->fwd[i] && x->fwd[i]->key < key) x = x->fwd[i];
            upd[i] = x;
        }
        x = x->fwd[0];
        if (!x || x->key != key) return false;
        for (int i = 0; i < level; ++i) {
            if (upd[i]->fwd[i] != x) continue;
            upd[i]->fwd[i] = x->fwd[i];
        }
        delete x;
        while (level > 1 && !head->fwd[level - 1]) --level;
        return true;
    }
};

int main() {
    SkipList sl;
    for (int k : {3, 6, 7, 9, 12}) sl.insert(k);
    assert(sl.search(7) && !sl.search(8));
    assert(sl.erase(6) && !sl.search(6));
    cout << "SkipList OK" << endl;
    return 0;
}
