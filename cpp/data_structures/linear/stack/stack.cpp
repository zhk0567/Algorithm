#include <bits/stdc++.h>
using namespace std;

struct ArrayStack {
    vector<int> a;
    void push(int x) { a.push_back(x); }
    void pop() {
        if (a.empty()) throw underflow_error("pop");
        a.pop_back();
    }
    int top() const {
        if (a.empty()) throw underflow_error("top");
        return a.back();
    }
};

struct Node {
    int val;
    Node* next;
    Node(int v, Node* n = nullptr) : val(v), next(n) {}
};

struct LinkedStack {
    Node* head = nullptr;
    void push(int x) { head = new Node(x, head); }
    void pop() {
        if (!head) throw underflow_error("pop");
        Node* t = head;
        head = head->next;
        delete t;
    }
    int top() const {
        if (!head) throw underflow_error("top");
        return head->val;
    }
};

struct MinStack {
    vector<int> s, mins;
    void push(int x) {
        s.push_back(x);
        if (mins.empty() || x <= mins.back()) mins.push_back(x);
    }
    void pop() {
        if (s.empty()) throw underflow_error("pop");
        int x = s.back();
        s.pop_back();
        if (!mins.empty() && x == mins.back()) mins.pop_back();
    }
    int top() const {
        if (s.empty()) throw underflow_error("top");
        return s.back();
    }
    int getMin() const {
        if (mins.empty()) throw underflow_error("getMin");
        return mins.back();
    }
};

int main() {
    ArrayStack st;
    st.push(1);
    st.push(2);
    assert(st.top() == 2);
    st.pop();
    assert(st.top() == 1);

    LinkedStack ls;
    ls.push(3);
    assert(ls.top() == 3);
    ls.pop();

    MinStack ms;
    ms.push(2);
    ms.push(1);
    ms.push(1);
    assert(ms.getMin() == 1);
    ms.pop();
    assert(ms.getMin() == 1);
    ms.pop();
    assert(ms.getMin() == 2);
    cout << "Stack OK" << endl;
    return 0;
}
