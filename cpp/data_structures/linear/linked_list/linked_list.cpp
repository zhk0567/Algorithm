#include <alg_std.hpp>
#include <cassert>
using namespace std;

struct SNode {
    int val;
    SNode* next;
    SNode(int v, SNode* n = nullptr) : val(v), next(n) {}
};

struct SinglyLinkedList {
    SNode dummy{0, nullptr};

    void append(int v) {
        SNode* cur = &dummy;
        while (cur->next) cur = cur->next;
        cur->next = new SNode(v);
    }

    void prepend(int v) { dummy.next = new SNode(v, dummy.next); }

    void reverse() {
        SNode* prev = nullptr;
        SNode* cur = dummy.next;
        dummy.next = nullptr;
        while (cur) {
            SNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        dummy.next = prev;
    }

    vector<int> to_vector() const {
        vector<int> out;
        for (SNode* p = dummy.next; p; p = p->next) out.push_back(p->val);
        return out;
    }

    void clear() {
        SNode* p = dummy.next;
        dummy.next = nullptr;
        while (p) {
            SNode* n = p->next;
            delete p;
            p = n;
        }
    }
};

struct DNode {
    int val;
    DNode *prev, *next;
    DNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    DNode head{0}, tail{0};
    DoublyLinkedList() {
        head.next = &tail;
        tail.prev = &head;
    }

    void append(int v) {
        DNode* node = new DNode(v);
        DNode* p = tail.prev;
        p->next = node;
        node->prev = p;
        node->next = &tail;
        tail.prev = node;
    }

    void remove(DNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    vector<int> to_vector() const {
        vector<int> out;
        for (DNode* p = head.next; p != &tail; p = p->next) out.push_back(p->val);
        return out;
    }
};

int main() {
    SinglyLinkedList s;
    s.append(1);
    s.append(2);
    s.prepend(0);
    assert(s.to_vector() == vector<int>({0, 1, 2}));
    s.reverse();
    assert(s.to_vector() == vector<int>({2, 1, 0}));
    s.clear();

    DoublyLinkedList d;
    d.append(1);
    d.append(2);
    assert(d.to_vector() == vector<int>({1, 2}));
    d.remove(d.tail.prev->prev);  // remove 1
    assert(d.to_vector() == vector<int>({2}));
    cout << "LinkedList OK" << endl;
    return 0;
}
