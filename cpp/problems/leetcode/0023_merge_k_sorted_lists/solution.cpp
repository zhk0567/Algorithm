// LeetCode 23
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto* h : lists)
            if (h) pq.push(h);
        ListNode dummy;
        ListNode* cur = &dummy;
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            cur->next = top;
            cur = top;
            if (top->next) pq.push(top->next);
        }
        cur->next = nullptr;
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
    vector<ListNode*> lists{fromList({1, 4, 5}), fromList({1, 3, 4}), fromList({2, 6})};
    assert((toList(Solution().mergeKLists(lists)) ==
            vector<int>{1, 1, 2, 3, 4, 4, 5, 6}));
    vector<ListNode*> empty{};
    assert(Solution().mergeKLists(empty) == nullptr);
    vector<ListNode*> partial{nullptr, fromList({1})};
    assert((toList(Solution().mergeKLists(partial)) == vector<int>{1}));
    cout << "0023 OK" << endl;
    return 0;
}
