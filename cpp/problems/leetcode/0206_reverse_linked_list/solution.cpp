// LeetCode 206
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v = 0, ListNode* n = nullptr) : val(v), next(n) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

vector<int> to_vec(ListNode* n) {
    vector<int> o;
    for (; n; n = n->next) o.push_back(n->val);
    return o;
}

ListNode* from_vec(const vector<int>& a) {
    ListNode d(0);
    ListNode* c = &d;
    for (int x : a) {
        c->next = new ListNode(x);
        c = c->next;
    }
    return d.next;
}

int main() {
    ListNode* h = from_vec({1, 2, 3, 4, 5});
    ListNode* r = Solution().reverseList(h);
    assert(to_vec(r) == vector<int>({5, 4, 3, 2, 1}));
    cout << "0206 OK" << endl;
    return 0;
}
