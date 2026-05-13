#include <bits/stdc++.h>
using namespace std;

struct MinHeap {
    vector<int> a;

    void sift_up(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (a[p] <= a[i]) break;
            swap(a[p], a[i]);
            i = p;
        }
    }

    void sift_down(int i) {
        int n = (int)a.size();
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, sm = i;
            if (l < n && a[l] < a[sm]) sm = l;
            if (r < n && a[r] < a[sm]) sm = r;
            if (sm == i) break;
            swap(a[i], a[sm]);
            i = sm;
        }
    }

    void push(int x) {
        a.push_back(x);
        sift_up((int)a.size() - 1);
    }

    int pop() {
        if (a.empty()) throw underflow_error("pop");
        if (a.size() == 1) {
            int v = a.back();
            a.pop_back();
            return v;
        }
        int root = a[0];
        a[0] = a.back();
        a.pop_back();
        sift_down(0);
        return root;
    }

    int top() const {
        if (a.empty()) throw underflow_error("top");
        return a[0];
    }
};

int main() {
    MinHeap h;
    for (int x : {5, 3, 7, 1}) h.push(x);
    assert(h.top() == 1);
    assert(h.pop() == 1);
    assert(h.pop() == 3);
    cout << "Heap OK" << endl;
    return 0;
}
