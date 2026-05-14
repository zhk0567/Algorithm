// LeetCode 155
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class MinStack {
public:
    void push(int val) {
        st.push_back(val);
        mn.push_back(mn.empty() ? val : min(mn.back(), val));
    }
    void pop() {
        st.pop_back();
        mn.pop_back();
    }
    int top() { return st.back(); }
    int getMin() { return mn.back(); }

private:
    vector<int> st, mn;
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    assert(s.getMin() == -3);
    s.pop();
    assert(s.top() == 0);
    assert(s.getMin() == -2);
    cout << "0155 OK" << endl;
    return 0;
}
