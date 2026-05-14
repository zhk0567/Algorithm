// LeetCode 21
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
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
    ListNode* a = from_vec({1, 2, 4});
    ListNode* b = from_vec({1, 3, 4});
    ListNode* m = Solution().mergeTwoLists(a, b);
    assert(to_vec(m) == vector<int>({1, 1, 2, 3, 4, 4}));
    cout << "0021 OK" << endl;
    return 0;
}
