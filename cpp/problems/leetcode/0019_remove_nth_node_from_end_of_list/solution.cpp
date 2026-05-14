// LeetCode 19
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for (int i = 0; i < n + 1; ++i) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
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
    assert((toList(Solution().removeNthFromEnd(fromList({1, 2, 3, 4, 5}), 2)) ==
            vector<int>{1, 2, 3, 5}));
    assert((toList(Solution().removeNthFromEnd(fromList({1}), 1)) == vector<int>{}));
    assert((toList(Solution().removeNthFromEnd(fromList({1, 2}), 1)) == vector<int>{1}));
    cout << "0019 OK" << endl;
    return 0;
}
