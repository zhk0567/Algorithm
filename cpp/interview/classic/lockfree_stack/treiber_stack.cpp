// Treiber 无锁栈（最小实现；教学用，未处理 ABA）
#include <bits/stdc++.h>
#include <cassert>
#include <atomic>
#include <optional>
#include <thread>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class TreiberStack {
public:
    ~TreiberStack() {
        while (Node* h = head_.exchange(nullptr, memory_order_acq_rel)) {
            while (h) {
                Node* n = h->next;
                delete h;
                h = n;
            }
        }
    }

    void push(int v) {
        Node* n = new Node{v, nullptr};
        Node* h = head_.load(memory_order_relaxed);
        do {
            n->next = h;
        } while (!head_.compare_exchange_weak(h, n, memory_order_release, memory_order_relaxed));
    }

    optional<int> try_pop() {
        Node* h = head_.load(memory_order_acquire);
        while (h) {
            Node* nxt = h->next;
            if (head_.compare_exchange_weak(h, nxt, memory_order_acq_rel, memory_order_acquire)) {
                int v = h->val;
                delete h;
                return v;
            }
            h = head_.load(memory_order_acquire);
        }
        return nullopt;
    }

private:
    atomic<Node*> head_{nullptr};
};

int main() {
    TreiberStack st;
    vector<thread> ts;
    for (int i = 0; i < 8; ++i) {
        ts.emplace_back([&st, i] {
            for (int j = 0; j < 50; ++j) st.push(i * 1000 + j);
        });
    }
    for (auto& t : ts) t.join();
    int cnt = 0;
    while (st.try_pop().has_value()) ++cnt;
    assert(cnt == 400);
    cout << "treiber_stack OK" << endl;
    return 0;
}
