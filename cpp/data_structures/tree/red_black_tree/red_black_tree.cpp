// 红黑树：插入 + 中序（教学实现）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

enum Color { RED, BLACK };

struct RBNode {
    int key;
    Color color;
    RBNode *l, *r, *p;
    explicit RBNode(int k) : key(k), color(RED), l(nullptr), r(nullptr), p(nullptr) {}
};

struct RedBlackTree {
    RBNode* root = nullptr;

    void leftRotate(RBNode* x) {
        RBNode* y = x->r;
        x->r = y->l;
        if (y->l) y->l->p = x;
        y->p = x->p;
        if (!x->p) root = y;
        else if (x == x->p->l) x->p->l = y;
        else x->p->r = y;
        y->l = x;
        x->p = y;
    }

    void rightRotate(RBNode* y) {
        RBNode* x = y->l;
        y->l = x->r;
        if (x->r) x->r->p = y;
        x->p = y->p;
        if (!y->p) root = x;
        else if (y == y->p->r) y->p->r = x;
        else y->p->l = x;
        x->r = y;
        y->p = x;
    }

    void insertFixup(RBNode* z) {
        while (z->p && z->p->color == RED) {
            RBNode* gp = z->p->p;
            if (z->p == gp->l) {
                RBNode* y = gp->r;
                if (y && y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->p->r) {
                        z = z->p;
                        leftRotate(z);
                    }
                    z->p->color = BLACK;
                    gp->color = RED;
                    rightRotate(gp);
                }
            } else {
                RBNode* y = gp->l;
                if (y && y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->p->l) {
                        z = z->p;
                        rightRotate(z);
                    }
                    z->p->color = BLACK;
                    gp->color = RED;
                    leftRotate(gp);
                }
            }
        }
        if (root) root->color = BLACK;
    }

    void insert(int key) {
        RBNode* z = new RBNode(key);
        RBNode* y = nullptr;
        RBNode* x = root;
        while (x) {
            y = x;
            if (key < x->key) x = x->l;
            else if (key > x->key) x = x->r;
            else {
                delete z;
                return;
            }
        }
        z->p = y;
        if (!y) root = z;
        else if (key < y->key) y->l = z;
        else y->r = z;
        insertFixup(z);
    }

    bool search(int key) const {
        RBNode* x = root;
        while (x) {
            if (key == x->key) return true;
            x = key < x->key ? x->l : x->r;
        }
        return false;
    }

    void inorderCollect(RBNode* n, vector<int>& out) const {
        if (!n) return;
        inorderCollect(n->l, out);
        out.push_back(n->key);
        inorderCollect(n->r, out);
    }

    vector<int> inorder() const {
        vector<int> out;
        inorderCollect(root, out);
        return out;
    }
};

int checkRb(RBNode* n) {
    if (!n) return 1;
    if (n->color == RED) {
        if ((n->l && n->l->color == RED) || (n->r && n->r->color == RED))
            throw runtime_error("red-red");
    }
    int lb = checkRb(n->l), rb = checkRb(n->r);
    if (lb != rb) throw runtime_error("bh");
    return lb + (n->color == RED ? 0 : 1);
}

int main() {
    RedBlackTree t;
    vector<int> keys{10, 20, 30, 15, 25, 5, 1};
    for (int k : keys) t.insert(k);
    auto ord = t.inorder();
    vector<int> sorted = keys;
    sort(sorted.begin(), sorted.end());
    assert(ord == sorted);
    assert(t.search(25) && !t.search(99));
    if (t.root) {
        assert(t.root->color == BLACK);
        checkRb(t.root);
    }
    cout << "red_black_tree OK" << endl;
    return 0;
}
