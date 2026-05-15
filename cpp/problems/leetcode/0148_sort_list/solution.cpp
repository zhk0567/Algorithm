// LeetCode 148
#include <alg_std.hpp>
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }

private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (a && b) {
            if (a->val <= b->val) {
                cur->next = a;
                a = a->next;
            } else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        cur->next = a ? a : b;
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
    assert((toList(Solution().sortList(fromList({4, 2, 1, 3}))) ==
            vector<int>{1, 2, 3, 4}));
    assert((toList(Solution().sortList(fromList({-1, 5, 3, 4, 0}))) ==
            vector<int>{-1, 0, 3, 4, 5}));
    assert(Solution().sortList(nullptr) == nullptr);
    cout << "0148 OK" << endl;
    return 0;
}
