#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    array<TrieNode*, 26> ch{};
    bool end = false;
};

struct Trie {
    TrieNode* root = new TrieNode();

    void insert(const string& w) {
        TrieNode* n = root;
        for (char c : w) {
            int i = c - 'a';
            if (!n->ch[i]) n->ch[i] = new TrieNode();
            n = n->ch[i];
        }
        n->end = true;
    }

    bool search(const string& w) const {
        TrieNode* n = root;
        for (char c : w) {
            int i = c - 'a';
            if (!n->ch[i]) return false;
            n = n->ch[i];
        }
        return n->end;
    }

    bool startsWith(const string& p) const {
        TrieNode* n = root;
        for (char c : p) {
            int i = c - 'a';
            if (!n->ch[i]) return false;
            n = n->ch[i];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    assert(t.search("apple") && !t.search("app"));
    assert(t.startsWith("app"));
    cout << "Trie OK" << endl;
    return 0;
}
