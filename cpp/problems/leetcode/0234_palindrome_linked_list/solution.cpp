// LeetCode 234
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr, *cur = slow;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        for (ListNode *a = head, *b = prev; b; a = a->next, b = b->next)
            if (a->val != b->val) return false;
        return true;
    }
};

static ListNode* fromList(vector<int> vs) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int v : vs) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy.next;
}

int main() {
    assert(Solution().isPalindrome(fromList({1, 2, 2, 1})));
    assert(!Solution().isPalindrome(fromList({1, 2})));
    assert(Solution().isPalindrome(fromList({1})));
    cout << "0234 OK" << endl;
    return 0;
}
