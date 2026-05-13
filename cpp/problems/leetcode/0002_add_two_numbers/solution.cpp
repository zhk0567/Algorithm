// LeetCode 2: Add Two Numbers
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v = 0, ListNode* n = nullptr) : val(v), next(n) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int c = 0;
        while (l1 || l2 || c) {
            int s = c;
            if (l1) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }
            c = s / 10;
            cur->next = new ListNode(s % 10);
            cur = cur->next;
        }
        return dummy.next;
    }
};

vector<int> to_vec(ListNode* n) {
    vector<int> o;
    for (; n; n = n->next) o.push_back(n->val);
    return o;
}

ListNode* from_vec(const vector<int>& a) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int x : a) {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy.next;
}

int main() {
    ListNode* l1 = from_vec({2, 4, 3});
    ListNode* l2 = from_vec({5, 6, 4});
    ListNode* ans = Solution().addTwoNumbers(l1, l2);
    assert(to_vec(ans) == vector<int>({7, 0, 8}));
    cout << "0002 OK" << endl;
    return 0;
}
