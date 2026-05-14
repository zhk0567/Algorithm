#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct CircularDeque {
    vector<int> buf;
    int cap, front, sz;
    explicit CircularDeque(int c = 8) : cap(max(4, c)), front(0), sz(0) { buf.assign(cap, 0); }

    void grow() {
        vector<int> nb(cap * 2, 0);
        for (int i = 0; i < sz; ++i) nb[i] = buf[(front + i) % cap];
        buf.swap(nb);
        cap = (int)buf.size();
        front = 0;
    }

    void push_back(int x) {
        if (sz == cap) grow();
        int idx = (front + sz) % cap;
        buf[idx] = x;
        ++sz;
    }

    void push_front(int x) {
        if (sz == cap) grow();
        front = (front - 1 + cap) % cap;
        buf[front] = x;
        ++sz;
    }

    int pop_back() {
        if (sz == 0) throw underflow_error("pop_back");
        int idx = (front + sz - 1) % cap;
        --sz;
        return buf[idx];
    }

    int pop_front() {
        if (sz == 0) throw underflow_error("pop_front");
        int v = buf[front];
        front = (front + 1) % cap;
        --sz;
        return v;
    }
};

int main() {
    CircularDeque d(4);
    d.push_back(1);
    d.push_front(0);
    d.push_back(2);
    assert(d.pop_front() == 0);
    assert(d.pop_back() == 2);
    assert(d.pop_front() == 1);
    cout << "Deque OK" << endl;
    return 0;
}
