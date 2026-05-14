// LeetCode 25
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        while (true) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) return dummy.next;
            }
            ListNode* grp_head = pre->next;
            ListNode* next_grp = tail->next;
            tail->next = nullptr;
            auto [nh, nt] = reverseList(grp_head);
            pre->next = nh;
            nt->next = next_grp;
            pre = nt;
        }
    }

private:
    pair<ListNode*, ListNode*> reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return {prev, head};
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
    assert((toList(Solution().reverseKGroup(fromList({1, 2, 3, 4, 5}), 2)) ==
            vector<int>{2, 1, 4, 3, 5}));
    assert((toList(Solution().reverseKGroup(fromList({1, 2, 3, 4, 5}), 3)) ==
            vector<int>{3, 2, 1, 4, 5}));
    assert((toList(Solution().reverseKGroup(fromList({1, 2}), 1)) ==
            vector<int>{1, 2}));
    cout << "0025 OK" << endl;
    return 0;
}
