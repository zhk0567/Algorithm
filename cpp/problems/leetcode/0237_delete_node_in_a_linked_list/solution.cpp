// LeetCode 237
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    ListNode a(4), b(5), c(1), d(9);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution().deleteNode(&b);
    vector<int> out;
    for (ListNode* p = &a; p; p = p->next) out.push_back(p->val);
    assert((out == vector<int>{4, 1, 9}));
    cout << "0237 OK" << endl;
    return 0;
}
