// LeetCode 208: Implement Trie (Prefix Tree)
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Trie {
    struct Node {
        array<Node*, 26> ch{};
        bool end = false;
        Node() { ch.fill(nullptr); }
    };
    Node* root;

    int idx(char c) const { return c - 'a'; }

public:
    Trie() { root = new Node(); }

    void insert(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = idx(c);
            if (!cur->ch[i]) cur->ch[i] = new Node();
            cur = cur->ch[i];
        }
        cur->end = true;
    }

    bool search(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = idx(c);
            if (!cur->ch[i]) return false;
            cur = cur->ch[i];
        }
        return cur->end;
    }

    bool startsWith(const string& prefix) {
        Node* cur = root;
        for (char c : prefix) {
            int i = idx(c);
            if (!cur->ch[i]) return false;
            cur = cur->ch[i];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    assert(t.search("apple"));
    assert(!t.search("app"));
    assert(t.startsWith("app"));
    t.insert("");
    assert(t.search(""));
    assert(t.startsWith(""));
    cout << "0208 OK" << endl;
    return 0;
}
