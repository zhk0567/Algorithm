// 手写 LRU Cache（双向链表 + 哈希）
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class LRUCache {
public:
    explicit LRUCache(int capacity) : cap(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int get(int key) {
        auto it = idx.find(key);
        if (it == idx.end()) return -1;
        moveToFront(it->second);
        return it->second->val;
    }

    void put(int key, int value) {
        auto it = idx.find(key);
        if (it != idx.end()) {
            it->second->val = value;
            moveToFront(it->second);
            return;
        }
        Node* node = new Node{key, value, nullptr, nullptr};
        idx[key] = node;
        addToFront(node);
        if ((int)idx.size() > cap) {
            Node* evict = tail->prev;
            removeNode(evict);
            idx.erase(evict->key);
            delete evict;
        }
    }

    int size() const { return (int)idx.size(); }

private:
    struct Node {
        int key{0};
        int val{0};
        Node* prev{nullptr};
        Node* next{nullptr};
    };

    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> idx;

    void addToFront(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = node->next = nullptr;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
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
    assert(c.get(1) == -1);
    assert(c.get(3) == 3);
    assert(c.get(4) == 4);
    c.put(4, 40);
    assert(c.get(4) == 40);
    assert(c.size() == 2);
    cout << "lru_cache OK" << endl;
    return 0;
}
