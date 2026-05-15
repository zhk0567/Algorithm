// LeetCode 24
#include <alg_std.hpp>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        while (pre->next && pre->next->next) {
            ListNode* a = pre->next;
            ListNode* b = a->next;
            a->next = b->next;
            b->next = a;
            pre->next = b;
            pre = a;
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
    assert((toList(Solution().swapPairs(fromList({1, 2, 3, 4}))) ==
            vector<int>{2, 1, 4, 3}));
    assert((toList(Solution().swapPairs(fromList({1}))) == vector<int>{1}));
    assert(Solution().swapPairs(nullptr) == nullptr);
    cout << "0024 OK" << endl;
    return 0;
}
