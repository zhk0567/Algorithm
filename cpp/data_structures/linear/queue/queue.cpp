#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct CircularArrayQueue {
    vector<int> buf;
    int cap, front, sz;
    explicit CircularArrayQueue(int c = 8) : cap(max(2, c)), front(0), sz(0) { buf.assign(cap, 0); }

    void enqueue(int x) {
        if (sz == cap - 1) {
            vector<int> nb(cap * 2, 0);
            for (int i = 0; i < sz; ++i) nb[i] = buf[(front + i) % cap];
            buf.swap(nb);
            cap = (int)buf.size();
            front = 0;
        }
        int rear = (front + sz) % cap;
        buf[rear] = x;
        ++sz;
    }

    int dequeue() {
        if (sz == 0) throw underflow_error("dequeue");
        int v = buf[front];
        front = (front + 1) % cap;
        --sz;
        return v;
    }
};

struct StackQueue {
    stack<int> in_, out_;
    void enqueue(int x) { in_.push(x); }
    int dequeue() {
        if (out_.empty()) {
            while (!in_.empty()) {
                out_.push(in_.top());
                in_.pop();
            }
        }
        if (out_.empty()) throw underflow_error("dequeue");
        int v = out_.top();
        out_.pop();
        return v;
    }
};

int main() {
    CircularArrayQueue q(4);
    q.enqueue(1);
    q.enqueue(2);
    assert(q.dequeue() == 1);
    q.enqueue(3);
    assert(q.dequeue() == 2);

    StackQueue sq;
    sq.enqueue(1);
    sq.enqueue(2);
    assert(sq.dequeue() == 1);
    cout << "Queue OK" << endl;
    return 0;
}
