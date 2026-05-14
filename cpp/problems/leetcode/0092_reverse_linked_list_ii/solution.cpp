// LeetCode 92
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        for (int i = 0; i < left - 1; ++i) pre = pre->next;
        ListNode* cur = pre->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy.next;
    }
};

static ListNode* fromList(vector<int> vs) {
    ListNode dummy;
    ListNode* cur = &dummy;
    for (int v : vs) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy.next;
}

static vector<int> toList(ListNode* h) {
    vector<int> out;
    while (h) {
        out.push_back(h->val);
        h = h->next;
    }
    return out;
}

int main() {
    assert((toList(Solution().reverseBetween(fromList({1, 2, 3, 4, 5}), 2, 4)) ==
            vector<int>{1, 4, 3, 2, 5}));
    assert((toList(Solution().reverseBetween(fromList({5}), 1, 1)) ==
            vector<int>{5}));
    cout << "0092 OK" << endl;
    return 0;
}
