#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *l, *r;
    explicit Node(int k) : key(k), l(nullptr), r(nullptr) {}
};

struct BST {
    Node* root = nullptr;

    bool search(int key) const {
        Node* n = root;
        while (n) {
            if (key == n->key) return true;
            n = key < n->key ? n->l : n->r;
        }
        return false;
    }

    void insert(int key) {
        if (!root) {
            root = new Node(key);
            return;
        }
        Node* n = root;
        while (true) {
            if (key == n->key) return;
            if (key < n->key) {
                if (!n->l) {
                    n->l = new Node(key);
                    return;
                }
                n = n->l;
            } else {
                if (!n->r) {
                    n->r = new Node(key);
                    return;
                }
                n = n->r;
            }
        }
    }

    Node* minNode(Node* n) {
        while (n->l) n = n->l;
        return n;
    }

    Node* del(Node* n, int key) {
        if (!n) throw out_of_range("delete");
        if (key < n->key) n->l = del(n->l, key);
        else if (key > n->key) n->r = del(n->r, key);
        else {
            if (!n->l) {
                Node* t = n->r;
                delete n;
                return t;
            }
            if (!n->r) {
                Node* t = n->l;
                delete n;
                return t;
            }
            Node* s = minNode(n->r);
            n->key = s->key;
            n->r = del(n->r, s->key);
        }
        return n;
    }

    void inorder(Node* n, vector<int>& out) const {
        if (!n) return;
        inorder(n->l, out);
        out.push_back(n->key);
        inorder(n->r, out);
    }
};

int main() {
    BST t;
    for (int x : {5, 3, 7, 2, 4, 6, 8}) t.insert(x);
    vector<int> ord;
    t.inorder(t.root, ord);
    assert(ord == vector<int>({2, 3, 4, 5, 6, 7, 8}));
    assert(t.search(4) && !t.search(9));
    t.root = t.del(t.root, 3);
    ord.clear();
    t.inorder(t.root, ord);
    assert(ord == vector<int>({2, 4, 5, 6, 7, 8}));
    cout << "BST OK" << endl;
    return 0;
}
