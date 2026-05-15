#include <alg_std.hpp>
#include <cassert>
using namespace std;

struct Node {
    int key, h;
    Node *l, *r;
    explicit Node(int k) : key(k), h(1), l(nullptr), r(nullptr) {}
};

int height(Node* n) { return n ? n->h : 0; }

void upd(Node* n) { n->h = 1 + max(height(n->l), height(n->r)); }

int bf(Node* n) { return height(n->l) - height(n->r); }

Node* rotR(Node* y) {
    Node* x = y->l;
    Node* t2 = x->r;
    x->r = y;
    y->l = t2;
    upd(y);
    upd(x);
    return x;
}

Node* rotL(Node* x) {
    Node* y = x->r;
    Node* t2 = y->l;
    y->l = x;
    x->r = t2;
    upd(x);
    upd(y);
    return y;
}

Node* insert(Node* n, int key) {
    if (!n) return new Node(key);
    if (key < n->key)
        n->l = insert(n->l, key);
    else if (key > n->key)
        n->r = insert(n->r, key);
    else
        return n;
    upd(n);
    int b = bf(n);
    if (b > 1 && n->l && key < n->l->key) return rotR(n);
    if (b > 1 && n->l && key > n->l->key) {
        n->l = rotL(n->l);
        return rotR(n);
    }
    if (b < -1 && n->r && key > n->r->key) return rotL(n);
    if (b < -1 && n->r && key < n->r->key) {
        n->r = rotR(n->r);
        return rotL(n);
    }
    return n;
}

Node* minNode(Node* n) {
    while (n->l) n = n->l;
    return n;
}

Node* rebalance(Node* n);

Node* del(Node* n, int key) {
    if (!n) throw out_of_range("del");
    if (key < n->key)
        n->l = del(n->l, key);
    else if (key > n->key)
        n->r = del(n->r, key);
    else {
        if (!n->l || !n->r) {
            Node* t = n->l ? n->l : n->r;
            delete n;
            return t;
        }
        Node* s = minNode(n->r);
        n->key = s->key;
        n->r = del(n->r, s->key);
    }
    return rebalance(n);
}

Node* rebalance(Node* n) {
    if (!n) return nullptr;
    upd(n);
    int b = bf(n);
    if (b > 1 && n->l && bf(n->l) >= 0) return rotR(n);
    if (b > 1 && n->l && bf(n->l) < 0) {
        n->l = rotL(n->l);
        return rotR(n);
    }
    if (b < -1 && n->r && bf(n->r) <= 0) return rotL(n);
    if (b < -1 && n->r && bf(n->r) > 0) {
        n->r = rotR(n->r);
        return rotL(n);
    }
    return n;
}

void inorder(Node* n, vector<int>& out) {
    if (!n) return;
    inorder(n->l, out);
    out.push_back(n->key);
    inorder(n->r, out);
}

int main() {
    Node* root = nullptr;
    for (int x : {10, 20, 30, 40, 50, 25}) root = insert(root, x);
    root = del(root, 20);
    vector<int> ord;
    inorder(root, ord);
    vector<int> cp = ord;
    sort(cp.begin(), cp.end());
    assert(ord == cp);
    cout << "AVL OK" << endl;
    return 0;
}
